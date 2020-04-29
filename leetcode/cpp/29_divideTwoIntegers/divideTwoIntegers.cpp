//
// Created by kayxhding on 2020-04-29 22:20:25
//

/*
 Given two integers dividend and divisor, divide two integers without using
multiplication, division and mod operator.

Return the quotient after dividing dividend by divisor.

The integer division should truncate toward zero, which means losing its
fractional part. For example, truncate(8.345) = 8 and truncate(-2.7335) = -2.

Example 1:

Input: dividend = 10, divisor = 3
Output: 3
Explanation: 10/3 = truncate(3.33333..) = 3.
Example 2:

Input: dividend = 7, divisor = -3
Output: -2
Explanation: 7/-3 = truncate(-2.33333..) = -2.
Note:

Both dividend and divisor will be 32-bit signed integers.
The divisor will never be 0.
Assume we are dealing with an environment which could only store integers within
the 32-bit signed integer range: [−231,  231 − 1]. For the purpose of this
problem, assume that your function returns 231 − 1 when the division
result overflows.
*/

#include <limits.h>
#include <cmath>
#include <iostream>
using namespace std;

class Solution {
 public:
  /*
  移位法：
  1. 将被除数、除数都转为正整数
  2. 根据dividend、divisor求符号sign是正的还是负的
  3. 将除数cmp不断进行移位， 判断移位后是否 (cmp << 1) >
  abs_dividend成立，如果成立，更新商 quotient <<= 1;更新除数cmp <<= 1;
  4. 退出循环后， 反向操作，cmp > abs_diviend成立话，更新quotient、cmp
  */
  int divide(int dividend, int divisor) {
    if (0 == divisor) {
      return 0;
    }

    int64_t result = 0;
    uint32_t quotient = 1;
    int64_t abs_dividend = abs(dividend);
    int64_t cmp = abs(divisor);
    int64_t abs_divisor = cmp;
    int sign = 1;
    if ((dividend > 0 && divisor < 0) || (dividend < 0 && divisor > 0)) {
      sign = -1;
    }

    while ((cmp << 1) <= abs_dividend) {
      quotient <<= 1;
      cmp <<= 1;
    }

    while (abs_dividend >= abs_divisor) {
      result += quotient;
      abs_dividend -= cmp;

      while (cmp > abs_dividend) {
        quotient >>= 1;
        cmp >>= 1;
      }
    }

    if (sign == 1) {
      if (result > INT_MAX) {
        return INT_MAX;
      }
      return result;
    }

    if (sign == -1) {
      if (-result < INT_MIN) {
        return INT_MAX;
      }
      return -result;
    }

    return result;
  }
};

int main() {
  Solution sol;
  auto result = sol.divide(10, 3);
  cout << result << endl;
}
