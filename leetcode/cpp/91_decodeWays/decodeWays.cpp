//
// Created by kayxhding on 2020-06-21 13:38:22
//
/*

A message containing letters from A-Z is being encoded to numbers using the
following mapping:

'A' -> 1
'B' -> 2
...
'Z' -> 26
Given a non-empty string containing only digits, determine the total number of
ways to decode it.

Example 1:

Input: "12"
Output: 2
Explanation: It could be decoded as "AB" (1 2) or "L" (12).
Example 2:

Input: "226"
Output: 3
Explanation: It could be decoded as "BZ" (2 26), "VF" (22 6), or "BBF" (2 2 6).
 */

#include <iostream>
#include <string>
using namespace std;

class Solution {
 public:
  /*
  1.递归

  2. 动态规划
  递归就是压栈压栈压栈，出栈出栈出栈的过程，我们可以利用动态规划的思想，省略压栈的过程，直接从
  bottom 到 top。

  用一个 dp 数组， dp [ i ] 代表字符串 s [ i, s.len-1 ]，也就是 s 从 i
  开始到结尾的字符串的解码方式。

  这样和递归完全一样的递推式。

  如果 s [ i ] 和 s [ i + 1 ] 组成的数字小于等于 26，那么

  dp [ i ] = dp[ i + 1 ] + dp [ i + 2 ]
*/

  int numDecodings(string s) {
    int dp[3] = {0};
    dp[s.length() % 3] = 1;
    if (s[s.length() - 1] != '0') {
      dp[(s.length() - 1) % 3] = 1;
    }

    for (int i = s.length() - 2; i >= 0; --i) {
      if (s[i] == '0') {
        dp[i % 3] = 0;
        continue;
      }

      int count1 = dp[(i + 1) % 3];
      int count2 = 0;
      int ten = (s[i] - '0') * 10;
      int one = s[i + 1] - '0';
      if (ten + one <= 26) {
        count2 = dp[(i + 2) % 3];
      }

      dp[i % 3] = count1 + count2;
    }

    return dp[0];
  }
#if 0
  int numDecodings(string s) { return numDecode(s, 0); }

  int numDecode(string s, int index) {
    if (index >= s.length()) {
      return 1;
    }

    if (s[0] == '0') {
      return 0;
    }

    int count1 = numDecode(s, index + 1);
    int count2 = 0;

    if (index < s.length() - 1) {
      int ten = (s[index] - '0') * 10;
      int one = s[index + 1] - '0';
      if (ten + one <= 26) {
        count2 = numDecode(s, index + 2);
      }
    }

    return count1 + count2;
  }
#endif
};

int main() {
  Solution sol;
  auto result = sol.numDecodings(
      "937159763112877694838719713226718867734994674234421784615493285912513492"
      "4241649584251978418763151253");
  cout << result << endl;
}
