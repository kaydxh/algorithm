//
// Created by kayxhding on 2020-05-21 08:31:51
//

/*
Implement pow(x, n), which calculates x raised to the power n (xn).

Example 1:

Input: 2.00000, 10
Output: 1024.00000
Example 2:

Input: 2.10000, 3
Output: 9.26100
Example 3:

Input: 2.00000, -2
Output: 0.25000
Explanation: 2-2 = 1/22 = 1/4 = 0.25
Note:

-100.0 < x < 100.0
n is a 32-bit signed integer, within the range [−231, 231 − 1]
*/

#include <cstdint>
#include <iostream>
using namespace std;

class Solution {
 public:
  /*
  递归法
  每次递归都会使得指数减少一半
  y = quickMul(x, n/2);
  1. 如果n为偶数，那么value= y * y
  2. n为奇数， value = y * y * x

  时间复杂度：
  O(logn)，即为递归的层数
  空间复杂度：
  O(logn)，即为递归的层数。这是由于递归的函数调用会使用栈空间

  方法二：
  快速幂 + 迭代
  x^n，其实就是把n转化为二进制后，把为1的位数不断进行x的平方叠加，若n=（101111)，
  那么 n= 2^0 + 2^1 + 2^2 + 2^3 +2^5）, x^n = x^(2^0) +  x^(2^1)  + x^(2^2) +
  x^(2^3) +  x^(2^5)

  时间复杂度：O(logn)，即为对 nn 进行二进制拆分的时间复杂度。
  空间复杂度：O(1)。
  */

  double myPow(double x, int n) {
    int64_t m = n;
    return m >= 0 ? quickMul(x, n) : 1.0 / quickMul(x, -n);
  }

#if 0
  double quickMul(double x, int n) {
    std::cout << "quickMul x: " << x << ", n: " << n << std::endl;
    if (n == 0) {
      return 1.0;
    }

    double y = quickMul(x, n / 2);
    return n % 2 == 0 ? y * y : y * y * x;
  }
#endif

  double quickMul(double x, int n) {
    double result = 1.0;
    double contribute = x;

    while (n > 0) {
      if (n % 2 == 1) {
        result *= contribute;
      }
      contribute *= contribute;
      n /= 2;
    }

    return result;
  }
};

int main() {
  Solution sol;
  auto result = sol.myPow(2, 10);
  cout << result << endl;
}
