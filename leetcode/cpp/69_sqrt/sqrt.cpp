//
// Created by kayxhding on 2020-05-21 13:14:05
//

/*
 Implement int sqrt(int x).

Compute and return the square root of x, where x is guaranteed to be a
non-negative integer.

Since the return type is an integer, the decimal digits are truncated and only
the integer part of the result is returned.

Example 1:

Input: 4
Output: 2
Example 2:

Input: 8
Output: 2
Explanation: The square root of 8 is 2.82842..., and since
             the decimal part is truncated, 2 is returned.
*/

#include <iostream>
using namespace std;

class Solution {
 public:
  /*
  二分查找的下界为 00，上界可以粗略地设定为
  xx。在二分查找的每一步中，我们只需要比较中间元素 mid 的平方与 x
  的大小关系，并通过比较的结果调整上下界的范围。由于我们所有的运算都是整数运算，不会存在误差，因此在得到最终的答案ans
  后，也就不需要再去尝试ans+1
  1. 注意判断 x为1的情况
  2. 这里需要middle * middle，因此需要将middle设置为int64_t类型，防止越界
  时间复杂度：O(logx)，即为二分查找需要的次数。
  空间复杂度：O(1)。
*/
  int mySqrt(int x) {
    if (x == 1) {
      return 1;
    }

    int result = 0;
    int left = 0;
    int right = x - 1;
    while (left <= right) {
      int64_t middle = left + (right - left) / 2;
      if (middle * middle < x) {
        result = middle;
        left = middle + 1;
      } else if (middle * middle > x) {
        right = middle - 1;
      } else if (middle * middle == x) {
        return middle;
      }
    }

    return result;
  }
};

int main() {
  Solution sol;
  {
    auto result = sol.mySqrt(8);
    cout << result << endl;
  }
  {
    auto result = sol.mySqrt(9);
    cout << result << endl;
  }
}
