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
#include <vector>
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

    /*
     * 动态规划
     * dp[i][j]代表字符串s[i][i...j], s.substr(i, j-i+1)是否为回文, 1是
     * 回文，0为非回文
     *
     * j -i -1 <= 1  => j-i <= 2  => j - i < 3 ( j-i < *
     * 3那么就最多只有1个元素，肯定是回文)
     *
     *   1. 时间复杂度O(n2)
     *   2. 空间复杂度O(n2)
     */
    string longestPalindromeDynamic(string s) {
        if (s.length() < 2) {
            return s;
        }

        int maxLen = 0;
        int begin = 0;
        vector<vector<int>> dp(s.length(), vector<int>(s.length()));
        // 对角线赋值true，因为对角线都是一个元素，肯定是回文
        for (int i = 0; i < s.length(); ++i) {
            dp[i][i] = 1;
        }

        for (int j = 1; j < s.length(); ++j) {
            for (int i = 0; i < j; ++i) {
                if (s[i] != s[j]) {
                    dp[i][j] = 0;
                } else {
                    if (j - i < 3) {
                        dp[i][j] = 1;
                    } else {
                        dp[i][j] = dp[i + 1][j - 1];
                    }
                }

                if (dp[i][j]) {
                    if (j - i + 1 > maxLen) {
                        maxLen = j - i + 1;
                        begin = i;
                    }
                }
            }
        }

        return s.substr(begin, maxLen);
    }
};

int main() {
    string s = "cbbd";
    Solution sol;
    auto result = sol.longestPalindromeDynamic(s);
    cout << result << endl;
    return 0;
}
