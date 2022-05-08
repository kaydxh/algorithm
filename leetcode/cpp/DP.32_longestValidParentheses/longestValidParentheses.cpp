/*
 * Given a string containing just the characters '(' and ')', find the length of
the longest valid (well-formed) parentheses substring. Example 1:

Input: s = "(()"
Output: 2
Explanation: The longest valid parentheses substring is "()".
Example 2:

Input: s = ")()())"
Output: 4
Explanation: The longest valid parentheses substring is "()()".
Example 3:

Input: s = ""
Output: 0
 

Constraints:

0 <= s.length <= 3 * 104
s[i] is '(', or ')'.

 */

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
   public:
    int longestValidParentheses(string s) {
        /*
         * 动态规划：
         * 1. dp[i] 代表从前面某个位置到i的字符串，最大有效子串长度
         * 2. 状态转移方程
         * 当前i节点如果是左括号，那就不可能是有效的括号对，因此在当前节
         * 点i是右括号时:
         *  s[i] == ")"
             1. i - dp[i-1] - 2 < 0
             // + 2是当前s[i]和 s[i - dp[i-1] - 1] 匹配
             * dp[i] = dp[i-1] + 2; // i -1 >= 0,
             * i - dp[i-1] - 1 >= 0, s[i - dp[i-1] - 1] == '('
             *
             2. i - dp[i-1] - 2 >= 0
             * dp[i] = dp[i-1] + 2 + dp[i - dp[i-1] - 2]; // i -1 >= 0,
             * i - dp[i-1] - 1 >= 0, s[i - dp[i-1] - 1] == '('

            时间复杂度：O(n)
            空间复杂度：O(n)
         */
        if (s.empty()) {
            return 0;
        }

        vector<int> dp(s.length());
        dp[0] = 0;

        int maxLen = 0;
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == ')' && i - 1 >= 0 && i - dp[i - 1] - 1 >= 0 &&
                s[i - dp[i - 1] - 1] == '(') {
                if (i - dp[i - 1] - 2 >= 0) {
                    dp[i] = dp[i - 1] + 2 + dp[i - dp[i - 1] - 2];
                } else {
                    dp[i] = dp[i - 1] + 2;
                }

                if (dp[i] > maxLen) {
                    maxLen = dp[i];
                }
            }
        }

        return maxLen;
    }
};

int main() {
    Solution sol;
    string s = ")()())";
    auto result = sol.longestValidParentheses(s);
    std::cout << result << std::endl;
}
