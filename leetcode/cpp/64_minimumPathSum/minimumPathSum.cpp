//
// Created by kayxhding on 2020-05-25 22:44:38
//

/*

Given a m x n grid filled with non-negative numbers, find a path from top left
to bottom right which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.

Example:

Input:
[
  [1,3,1],
  [1,5,1],
  [4,2,1]
]
Output: 7
Explanation: Because the path 1→3→1→1→1 minimizes the sum.
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  /*
  动态规划
  1. dp[i][j]为走到第i行第j列时，最小的数字总和
  2. dp[i][j] = min(dp[i-1][j] + dp[i][j-1]) + grid[i][j],
  第i行第j列时，最小的数字总和 = min(dp[i-1][j] + dp[i][j-1]) +
  当前第i行第j列第数字
  3. 因为上述表达式涉及到边界条件，不然会越界，所以需对边界到i和j进行特殊处理
  4. 当i == 0, j == 0时，dp[i][j] = grid[i][j]
  5. 当i = 0, j != 0时， dp[i][j] = dp[i][j-1] + grid[i][j]
  6. 当j = 0, i != 0时， dp[i][j] = dp[i - 1][j] + grid[i][j]

  复杂度：
  时间复杂度：O(M×N)
  空间复杂度：O(M*N)

  优化：
  其实我们完全不需要建立 dp 矩阵浪费额外空间，直接遍历
  grid[i][j]就地修改即可。这是因为：grid[i][j] = min(grid[i - 1][j], grid[i][j -
  1]) + grid[i][j] ；原 grid 矩阵元素中被覆盖为 dp
  元素后（都处于当前遍历点的左上方），不会再被使用到。
*/
  int minPathSum(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();

    vector<vector<int>> dp(m, vector<int>(n));
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (i == 0 && j == 0) {
          dp[i][j] = grid[i][j];
        } else if (i == 0) {
          dp[i][j] = dp[i][j - 1] + grid[i][j];
        } else if (j == 0) {
          dp[i][j] = dp[i - 1][j] + grid[i][j];
        } else {
          dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
        }
      }
    }

    return dp[m - 1][n - 1];
  }
};

int main() {
  vector<vector<int>> grid = {{1, 3, 1}, {1, 5, 1}, {4, 2, 1}};
  Solution sol;
  auto result = sol.minPathSum(grid);
  cout << result << endl;
}
