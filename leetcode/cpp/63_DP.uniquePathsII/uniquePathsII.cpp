//
// Created by kayxhding on 2020-05-24 18:08:23
//

/*
 A robot is located at the top-left corner of a m x n grid (marked 'Start' in
the diagram below).

The robot can only move either down or right at any point in time. The robot is
trying to reach the bottom-right corner of the grid (marked 'Finish' in the
diagram below).

Now consider if some obstacles are added to the grids. How many unique paths
would there be?

An obstacle and empty space is marked as 1 and 0 respectively in the grid.

Note: m and n will be at most 100.

Example 1:

Input:
[
  [0,0,0],
  [0,1,0],
  [0,0,0]
]
Output: 2
Explanation:
There is one obstacle in the middle of the 3x3 grid above.
There are two ways to reach the bottom-right corner:
1. Right -> Right -> Down -> Down
2. Down -> Down -> Right -> Right

*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    /*
   int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
     int m = obstacleGrid.size();
     int n = obstacleGrid[0].size();
     vector<vector<int>> dp(m + 1, vector<int>(n + 1));
     dp[0][1] = 1;
     for (int i = 1; i <= m; ++i) {
       for (int j = 1; j <= n; ++j) {
         if (obstacleGrid[i - 1][j - 1] == 1) {
           dp[i][j] = 0;
         } else {
           dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
         }
       }
     }

     return dp[m][n];
   }
   */

    /*
   动态规划：
   1. dp[i][j] 是到达 i, j 最多路径
   2. 动态方程：dp[i][j] = dp[i-1][j] +
   dp[i][j-1]（到达第i行第j列的路径数=到达i-1行第j列的路径数 +
   到达第i行第j-1列的路径数） 注意，对于第一行 dp[0][j]，或者第一列
   dp[i][0]，由于都是在边界，所以只能为 1

   复杂度：
   时间复杂度：O(m*n)
   空间复杂度：O(m * n)
   优化：因为我们每次只需要 dp[i-1][j],dp[i][j-1]
   所以我们只要记录这两个数
  */
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if (obstacleGrid.empty()) {
            return 0;
        }

        if (obstacleGrid[0].empty()) {
            return 0;
        }
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int>(n));
        //在第一列中，如果有障碍物，那么后续的位置都无法到达
        for (int i = 0; i < m; ++i) {
            if (obstacleGrid[i][0] == 1) {
                break;
            }
            dp[i][0] = 1;
        }
        //在第一行中，如果有障碍物，那么后续的位置都无法到达
        for (int j = 0; j < m; ++j) {
            if (obstacleGrid[0][j] == 1) {
                break;
            }
            dp[0][j] = 1;
        }
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                if (obstacleGrid[i][j] != 1) {
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
                }
            }
        }

        return dp[m - 1][n - 1];
    }
};

int main() {
    vector<vector<int>> obstacleGrid = {{0, 0, 0}, {0, 1, 0}, {0, 0, 0}};
    Solution sol;
    auto result = sol.uniquePathsWithObstacles(obstacleGrid);
    cout << result << endl;
}
