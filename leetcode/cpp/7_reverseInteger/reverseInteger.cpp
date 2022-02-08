//
// Created by kayxhding on 2020-04-14 23:05:44
//

/*
 Given a 32-bit signed integer, reverse digits of an integer.

Example 1:

Input: 123
Output: 321
Example 2:

Input: -123
Output: -321
Example 3:

Input: 120
Output: 21
Note:
Assume we are dealing with an environment which could only store integers within
the 32-bit signed integer range: [−231,  231 − 1]. For the purpose of this
problem, assume that your function returns 0 when the reversed integer
overflows.
*/

#include <limits.h>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
 public:
  /*
  //pop operation:
  pop = x % 10;
  x /= 10;

  //push operation:
  rev = rev * 10 + pop;

  1. 使用取模操作，获取数字x的最后一位， int n = % 10;
  2. 因为反转，所以下次遍历获取时，最后一位是要往前进一位的，因此 result =
  result
  * 10 + n
  3. 需要对溢出情况进行考虑
  注意：如果不反转整数的话，result +=  n * pow(10, i); 每次遍历后，++i

  复杂度分析
  1. 时间复杂度：O(log(x))，x 中大约有 log_{10}(x)位数字。
  2. 空间复杂度：O(1)。
*/
  int reverse(int x) {
    int result = 0;
    while (x > 0) {
      int n = x % 10;
      if (result > INT_MAX / 10 &&
          (result == INT_MAX / 10 && n > INT_MAX % 10)) {
        return 0;
      }

      if (result < INT_MIN / 10 &&
          (result == INT_MIN / 10 && n < INT_MIN % 10)) {
        return 0;
      }
      result = result * 10 + n;
      x /= 10;
    }

    return result;
  }
};

int main() {
  Solution sol;
  auto result = sol.reverse(123);
  cout << result << endl;
}
