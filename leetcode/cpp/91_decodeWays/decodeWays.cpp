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
};

int main() {
  Solution sol;
  auto result = sol.numDecodings(
      "937159763112877694838719713226718867734994674234421784615493285912513492"
      "4241649584251978418763151253");
  cout << result << endl;
}
