//
// Created by kayxhding on 2020-07-09 23:03:48
//

/*
   The n-queens puzzle is the problem of placing n queens on an n×n chessboard
such that no two queens attack each other.

Given an integer n, return all distinct solutions to the n-queens puzzle.

Each solution contains a distinct board configuration of the n-queens'
placement, where 'Q' and '.' both indicate a queen and an empty space
respectively.

Example:

Input: 4
Output: [
 [".Q..",  // Solution 1
  "...Q",
  "Q...",
  "..Q."],

 ["..Q.",  // Solution 2
  "Q...",
  "...Q",
  ".Q.."]
]
Explanation: There exist two distinct solutions to the 4-queens puzzle as shown
above.

*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>> result;
    vector<string> path(n, string(n, '.'));

    dfs(0, 0, path, result);
    return result;
  }

  bool dfs(int gap, int begin, vector<string> &path,
           vector<vector<string>> &result) {
    if (gap == path.size()) {
      result.push_back(path);
      return true;
    }

    for (int i = 0; i < path.size(); ++i) {
      if (!valid(path, begin, i)) {
        continue;
      }

      path[begin][i] = 'Q';
#if 1
      dfs(gap + 1, begin + 1, path, result);
#else
      // only get one method
      if (dfs(gap + 1, begin + 1, path, result)) {
        return true;
      }
#endif
      path[begin][i] = '.';
    }

    return false;
  }

  bool valid(vector<string> &path, int row, int col) {
    int n = path.size();

    //检测列冲突
    for (int i = 0; i < n; ++i) {
      if (path[i][col] == 'Q') {
        return false;
      }
    }

    //检测右上方是否冲突
    for (int i = row - 1, j = col + 1; i >= 0 && j <= n - 1; --i, ++j) {
      if (path[i][j] == 'Q') {
        return false;
      }
    }

    //检测左上方是否冲突
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
  auto result = sol.solveNQueens(10);
  for (auto rows : result) {
    for (auto e : rows) {
      cout << e << endl;
    }
    cout << endl;
  }
}
