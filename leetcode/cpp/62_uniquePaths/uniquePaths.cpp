//
// Created by kayxhding on 2020-05-24 17:32:02
//

/*
   A robot is located at the top-left corner of a m x n grid (marked 'Start' in
the diagram below). The robot can only move either down or right at any point in
time. The robot is trying to reach the bottom-right corner of the grid (marked
'Finish' in the diagram below). How many possible unique paths are there?

Above is a 7 x 3 grid. How many possible unique paths are there?

Example 1:
Input: m = 3, n = 2
Output: 3
Explanation:
From the top-left corner, there are a total of 3 ways to reach the bottom-right
corner:
1. Right -> Right -> Down
2. Right -> Down -> Right
3. Down -> Right -> Right
Example 2:

Input: m = 7, n = 3
Output: 28

Constraints:

1 <= m, n <= 100
It's guaranteed that the answer will be less than or equal to 2 * 10 ^ 9.
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
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
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n));
        for (int i = 0; i < m; ++i) {
            dp[i][0] = 1;
        }
        for (int j = 0; j < n; ++j) {
            dp[0][j] = 1;
        }
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }

        return dp[m - 1][n - 1];
    }

    //使用一维数组节省空间,将自身与前一个相加，重复利用计算结果
    int uniquePaths2(int m, int n) {
        vector<int> dp(n, 1);

        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                dp[j] += dp[j - 1];
            }
        }

        return dp[n - 1];
    }
};

int main() {
    Solution sol;
    auto result = sol.uniquePaths2(7, 3);
    cout << result << endl;
}
