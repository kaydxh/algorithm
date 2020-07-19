//
// Created by kayxhding on 2020-07-19 21:52:37
//

/*
   The n-queens puzzle is the problem of placing n queens on an n×n chessboard
such that no two queens attack each other.

Given an integer n, return the number of distinct solutions to the n-queens
puzzle.

Example:

Input: 4
Output: 2
Explanation: There are two distinct solutions to the 4-queens puzzle as shown
below.
[
 [".Q..",  // Solution 1
  "...Q",
  "Q...",
  "..Q."],

 ["..Q.",  // Solution 2
  "Q...",
  "...Q",
  ".Q.."]
]

*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  int totalNQueens(int n) {
    int result = 0;
    vector<string> path(n, string(n, '.'));
    backTrace(0, 0, path, result);
    return result;
  }

  void backTrace(int gap, int row, vector<string> &path, int &result) {
    // n is the number of row
    int n = path.size();
    if (gap == n) {
      ++result;
      return;
    }

    // n is the number col, which is equal row
    for (int i = 0; i < n; ++i) {
      if (!valid(row, i, n, path)) {
        continue;
      }

      path[row][i] = 'Q';
      backTrace(gap + 1, row + 1, path, result);
      path[row][i] = '.';
    }

    return;
  }

  bool valid(int row, int col, int n, const vector<string> &path) {
    if (row < 0 || row >= n || col < 0 || col >= n) {
      return false;
    }

    //列冲突
    for (int i = 0; i < n; ++i) {
      if (path[i][col] == 'Q') {
        return false;
      }
    }

    //右上角
    for (int i = row - 1, j = col + 1; i >= 0 && j < n; --i, ++j) {
      if (path[i][j] == 'Q') {
        return false;
      }
    }

    //左上角
    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; --i, --j) {
      if (path[i][j] == 'Q') {
        return false;
      }
    }

    return true;
  }
};

int main() {
  Solution sol;
  auto result = sol.totalNQueens(4);
  cout << result << endl;

  return 0;
}
