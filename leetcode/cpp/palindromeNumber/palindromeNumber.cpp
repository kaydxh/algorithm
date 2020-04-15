//
// Created by kayxhding on 2020-04-15 22:23:43
//
/*
Determine whether an integer is a palindrome. An integer is a palindrome when
it reads the same backward as forward.

Example 1:

Input: 121
Output: true
Example 2:

Input: -121
Output: false
Explanation: From left to right, it reads -121. From right to left, it becomes
121-. Therefore it is not a palindrome. Example 3:

Input: 10
Output: false
Explanation: Reads 01 from right to left. Therefore it is not a palindrome.
Follow up:

Coud you solve it without converting the integer to a string?

*/

#include <iostream>
using namespace std;

class Solution {
 public:
  /*
  1.
  第一个想法是将数字转换为字符串，并检查字符串是否为回文。但是，这需要额外的非常量空间来创建问题描述中所不允许的字符串。
  2.
  第二个想法是将数字本身反转，然后将反转后的数字与原始数字进行比较，如果它们是相同的，那么这个数字就是回文。
  但是，如果反转后的数字大于INT_MAX，我们将遇到整数溢出问题
  3.
  为了避免数字反转可能导致的溢出问题，为什么不考虑只反转数字的一半？毕竟，如果该数字是回文，其后半部分反转后应该与原始数字的前半部分相同

  时间复杂度：
  1.对于每次迭代，我们会将输入除以10，因此时间复杂度为
  O(log_{10}(n)) 10
  2. 空间复杂度：O(1)
*/
  bool isPalindrome(int x) {
    /*
    // 如上所述，当 x < 0 时，x 不是回文数。
    // 同样地，如果数字的最后一位是 0，为了使该数字为回文，
    // 则其第一位数字也应该是 0
    // 只有 0 满足这一属性
    */
    if (x < 0 || (x % 10 == 0 && x != 0)) {
      return false;
    }

    int reversed_number = 0;
    while (x > reversed_number) {
      int n = x % 10;
      reversed_number = reversed_number * 10 + n;
      x = x / 10;
    }
    // 当数字长度为奇数时，我们可以通过 reversed_number/10 去除处于中位的数字。
    // 例如，当输入为 12321 时，在 while 循环的末尾我们可以得到 x =
    // reversed_number = 123，
    // 由于处于中位的数字不影响回文（它总是与自己相等），所以我们可以简单地将其去除。
    return x == reversed_number || x == reversed_number / 10;
  }
};

int main() {
  int x = 121;
  Solution sol;
  auto result = sol.isPalindrome(x);
  cout << result << endl;
}
