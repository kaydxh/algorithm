//
// Created by kayxhding on 2020-04-13 23:00:21
//

/*
Given a string s, find the longest palindromic substring in s. You may assume
that the maximum length of s is 1000.

Example 1:

Input: "babad"
Output: "bab"
Note: "aba" is also a valid answer.
Example 2:

Input: "cbbd"
Output: "bb"
*/

#include <iostream>
#include <string>
using namespace std;

class Solution {
 public:
  /*
    如果一段字符串是回文串，那么以某个字符为中心的前缀和后缀必定是相同的，如aba，以b为中心，它的前缀和后缀都是a。因此，可以枚举中心位置，然后在该位置上扩展，记录并更新得到的最长回文串的长度
      复杂度：
      1. 时间复杂度O(n2)
  */
  string longestPalindrome(string s) {
    string result;
    int maxLen = 0;
    for (auto i = 0; i < s.length(); ++i) {
      for (auto j = 0; i - j >= 0 && i + j < s.length(); ++j) {
        if (s[i - j] != s[i + j]) {
          break;
        }
        if (2 * j + 1 > maxLen) {
          maxLen = 2 * j + 1;
          result = s.substr(i - j, 2 * j + 1);
        }
      }

      for (auto j = 0; i - j >= 0 && i + j + 1 < s.length(); ++j) {
        if (s[i - j] != s[i + j + 1]) {
          break;
        }

        if (2 * j + 2 > maxLen) {
          maxLen = 2 * j + 2;
          result = s.substr(i - j, 2 * j + 2);
        }
      }
    }

    return result;
  }
};

int main() {
  string s = "cbbd";
  Solution sol;
  auto result = sol.longestPalindrome(s);
  cout << result << endl;
  return 0;
}
