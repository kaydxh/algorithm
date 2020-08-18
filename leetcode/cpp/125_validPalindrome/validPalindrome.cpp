//
// Created by kayxhding on 2020-08-18 23:08:24
//

/*
   Given a string, determine if it is a palindrome, considering only
alphanumeric characters and ignoring cases.

Note: For the purpose of this problem, we define empty string as valid
palindrome.

Example 1:

Input: "A man, a plan, a canal: Panama"
Output: true
Example 2:

Input: "race a car"
Output: false
 

Constraints:

s consists only of printable ASCII characters.
*/

#include <iostream>
#include <string>
using namespace std;

class Solution {
 public:
  /*
  双指针法：
  1. 定义2个指针，first指向字符串的起始位置，second指向字符串的末尾
  2. first 向右增加，second向左减小过程中，如果字符串不是数字或字母就过滤调
  3. 如果是大写字母，就转化为小写字母
  4， 之后判断first和second的位置的字符是否相等，不等就返回false
  5. 全部遍历结束，返回true
  时间复杂度：O(n)
  空间复杂度：O(1)
  */

  bool isPalindrome(string s) {
    int first = 0;
    int second = (s.length() - 1 >= 0) ? (s.length() - 1) : 0;
    while (first < second) {
      while (first < second) {
        if (pureChar(s[first])) {
          break;
        }
        ++first;
      }

      while (first < second) {
        if (pureChar(s[second])) {
          break;
        }
        --second;
      }

      if (s[first] != s[second]) {
        return false;
      }
      ++first;
      --second;
    }

    return true;
  }

  bool pureChar(char &c) {
    if (c >= 'A' && c <= 'Z') {
      c += 'a' - 'A';
      return true;
    }

    int ans_code = c - '0';
    if (!(ans_code >= 0 && ans_code <= 9) && !(c >= 'a' && c <= 'z')) {
      return false;
    }
    return true;
  }
};

int main() {
  Solution sol;
  std::string s = "A man, a plan, a canal: Panama";
  auto result = sol.isPalindrome(s);
  cout << result << endl;
}
