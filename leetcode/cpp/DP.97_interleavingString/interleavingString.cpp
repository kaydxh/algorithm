
/*
 Given strings s1, s2, and s3, find whether s3 is formed by an interleaving of
s1 and s2.

An interleaving of two strings s and t is a configuration where they are divided
into non-empty substrings such that:

s = s1 + s2 + ... + sn
t = t1 + t2 + ... + tm
|n - m| <= 1
The interleaving is s1 + t1 + s2 + t2 + s3 + t3 + ... or t1 + s1 + t2 + s2 + t3
+ s3 + ... Note: a + b is the concatenation of strings a and b.
Note: a + b is the concatenation of strings a and b.

Example 1:
Input: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac"
Output: true

Example 2:
Input: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbbaccc"
Output: false

Example 3:
Input: s1 = "", s2 = "", s3 = ""
Output: true
 

Constraints:

0 <= s1.length, s2.length <= 100
0 <= s3.length <= 200
s1, s2, and s3 consist of lowercase English letters.
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
   public:
    /*
     * 动态规划：
     * 该题和路径题目一致
     * dp[i][j]代表从s1中前i个字符，从s2中前j个字符，能否拼装s3的前
     * i+j个字符
     * 状态转移方程
     * dp[0][0] = true
     * dp[i][0] i>=1 && i <= n1, s1[i-1] == s3[i-1]
     * dp[0][j] j>=1 && j <= n2, s2[j-1] == s3[j-1]
     * dp[i][j] = (dp[i - 1][j] && (s3[i + j - 1] == s1[i - 1])) ||
     *            (dp[i][j - 1] && (s3[i + j - 1] == s2[j - 1]));
     *
     */
    bool isInterleave(string s1, string s2, string s3) {
        int n1 = s1.length();
        int n2 = s2.length();
        int n3 = s3.length();
        if (n1 + n2 != n3) {
            return false;
        }
        vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1));
        dp[0][0] = true;

        for (int i = 1; i <= n1; ++i) {
            if (s3[i - 1] == s1[i - 1]) {
                dp[i][0] = true;
            } else {
                break;
            }
        }

        for (int j = 1; j <= n2; ++j) {
            if (s3[j - 1] == s2[j - 1]) {
                dp[0][j] = true;
            } else {
                break;
            }
        }

        for (int i = 1; i <= n1; ++i) {
            for (int j = 1; j <= n2; ++j) {
                dp[i][j] = (dp[i - 1][j] && (s3[i + j - 1] == s1[i - 1])) ||
                           (dp[i][j - 1] && (s3[i + j - 1] == s2[j - 1]));
            }
        }

        return dp[n1][n2];
    }
};

int main() {
    string s1 = "bacc";        //"aabcc";
    string s2 = "aabcce";      //"dbbca";
    string s3 = "abaacbccec";  //"aadbbcbcac";

    Solution sol;
    auto result = sol.isInterleave(s1, s2, s3);
    std::cout << result << std::endl;
}
