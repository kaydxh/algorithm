//
// Created by kayxhding on 2020-04-14 22:26:40
//

/*
 The string "PAYPALISHIRING" is written in a zigzag pattern on a given number
of rows like this: (you may want to display this pattern in a fixed font for
better legibility)

P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"

Write the code that will take a string and make this conversion given a number
of rows:

string convert(string s, int numRows);
Example 1:

Input: s = "PAYPALISHIRING", numRows = 3
Output: "PAHNAPLSIIGYIR"
Example 2:

Input: s = "PAYPALISHIRING", numRows = 4
Output: "PINALSIGYAHRPI"
Explanation:

P     I    N
A   L S  I G
Y A   H R
P     I
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
 public:
  /*
  1. 用vector<string> row_strings
  保存所有行的字符串，最后的输出字符串就是遍历row_strings，把每行的字符串相加起来
  2. 用int cur_row记录当前行，bool goDown记录当前方向，如果是第0行或者nowRow -
  1行时，需要反转方向(goDown = !goDown）
  3. 每次遍历， cur_row += goDown ? 1 : -1; 即如果向下走，行号+1， 否则行号-1
  注意：要对numRow为1时，进行判断，此时不需要改变方向，直接返回s，否则，goDown逻辑无法走通（必须改变方向）

  复杂度：
  1. 时间复杂度：O(n)
  2. 空间复杂度：O(n)
*/
  string convert(string s, int numRows) {
    //要对numRow为1时，进行判断，此时不需要改变方向，直接返回s，否则，goDown逻辑无法走通（必须改变方向）
    if (1 == numRows) {
      return s;
    }

    string result;
    int rows = numRows > s.length() ? s.length() : numRows;
    vector<string> row_strings(rows);
    row_strings.resize(rows);
    int cur_row = 0;
    bool goDown = false;
    for (auto i = 0; i < s.length(); ++i) {
      row_strings[cur_row] += s[i];
      if (cur_row == 0 || cur_row == numRows - 1) {
        goDown = !goDown;
      }

      cur_row += goDown ? 1 : -1;
    }

    for (auto i = 0; i < row_strings.size(); ++i) {
      result += row_strings[i];
    }

    return result;
  }
};

int main() {
  string s = "PAYPALISHIRING";
  Solution sol;
  auto result = sol.convert(s, 3);
  cout << result << endl;
  return 0;
}
