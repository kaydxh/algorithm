//
// Created by kayxhding on 2020-05-13 22:48:53
//

/*
 Given two binary strings, return their sum (also a binary string).

The input strings are both non-empty and contains only characters 1 or 0.

Example 1:

Input: a = "11", b = "1"
Output: "100"
Example 2:

Input: a = "1010", b = "1011"
Output: "10101"
 

Constraints:

Each string consists only of '0' or '1' characters.
1 <= a.length, b.length <= 10^4
Each string is either "0" or doesn't contain any leading zero.
*/

#include <iostream>
#include <string>
using namespace std;

class Solution {
 public:
  /*
  复杂度分析
  时间复杂度：O(max(N,M))，其中 N 和 M 是输入字符串 a 和 b 的长度。
  空间复杂度：O(max(N,M))，存储求和结果。
  */
  string addBinary(string a, string b) {
    string result;
    int n1 = a.length();
    int n2 = b.length();
    int carry = 0;
    int val1 = 0;
    int val2 = 0;
    for (int i = n1 - 1, j = n2 - 1; i >= 0 || j >= 0;) {
      if (n1 < 0) {
        val1 = 0;
      } else {
        val1 = a[i] - '0';
        --i;
      }

      if (n2 < 0) {
        val2 = 0;
      } else {
        val2 = b[j] - '0';
        --j;
      }

      int sum = val1 + val2 + carry;
      carry = sum / 2;
      int digit = sum % 2;
      result.insert(result.begin(), digit + '0');
    }

    if (carry > 0) {
      result.insert(result.begin(), carry + '0');
    }

    return result;
  }
};

int main() {
  string a = "1010";
  string b = "1011";
  Solution sol;
  auto result = sol.addBinary(a, b);
  cout << result << endl;
}
