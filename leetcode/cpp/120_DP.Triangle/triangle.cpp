/*
 * Given a triangle array, return the minimum path sum from top to bottom.

For each step, you may move to an adjacent number of the row below. More
formally, if you are on index i on the current row, you may move to either index
i or index i + 1 on the next row.


Example 1:

Input: triangle = [[2],[3,4],[6,5,7],[4,1,8,3]]
Output: 11
Explanation: The triangle looks like:
   2
  3 4
 6 5 7
4 1 8 3
The minimum path sum from top to bottom is 2 + 3 + 5 + 1 = 11 (underlined
above). Example 2:

Input: triangle = [[-10]]
Output: -10
 

Constraints:

1 <= triangle.length <= 200
triangle[0].length == 1
triangle[i].length == triangle[i - 1].length + 1
-104 <= triangle[i][j] <= 104
 

Follow up: Could you do this using only O(n) extra space, where n is the total
number of rows in the triangle?
 *
 */

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    /*
     * 动态规划
     * dp[i][j]代表第行第j列的最近路径和
     * 状态转移方程
     * dp[i][j] = min(dp[i-1][j-1] + dp[i-1][j]) + triangle[i][j];
     * 当j == 0时，状态转移方程没有意义，因此需要特殊处理：
     * dp[i][0]= dp[i-1][0] + triangle[i][0];
     * 当 i == j时， dp[i-1][j] 没有意义，j越界（第i行最多只有i个元素）,
     * 特殊处理: dp[i][i] = dp[i-1][i-1] + triangle[i][i];
        复杂度：
        时间复杂度O(n^2)
     */
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        if (n == 0) {
            return 0;
        }
        vector<vector<int>> dp(n, vector<int>(n));
        dp[0][0] = triangle[0][0];
        for (int i = 1; i < n; ++i) {
            //处理三角形最左边的数据
            dp[i][0] = dp[i - 1][0] + triangle[i][0];
            for (int j = 1; j < triangle[i].size(); ++j) {
                dp[i][j] = min(dp[i - 1][j - 1], dp[i - 1][j]) + triangle[i][j];
            }
            //处理三角形最右边的数据
            dp[i][i] = dp[i - 1][i - 1] + triangle[i][i];
        }

        return *min_element(dp[n - 1].begin(), dp[n - 1].end());
    }

    int minimumTotal2(vector<vector<int>>& triangle) {
        int n = triangle.size();
        if (n == 0) {
            return 0;
        }
        //空间优化，dp[i]只与dp[i-1]有关，
        // dp[i] 可以看作一维数组索引(三角形看作一维数组)i的最小路径和
        // dp[i] = min(dp[i], dp[i-1]) +
        // triangle[i][j]
        vector<int> dp(n + 1);
        for (int i = n - 1; i > 0; ++i) {
            for (int j = 0; j < triangle[i].size(); ++j) {
                dp[j] = min(dp[j + 1], dp[j]) + triangle[i][j];
            }
        }

        return dp[0];
    }
};

int main() {
    vector<vector<int>> triangle = {{2}, {3, 4}, {6, 5, 7}, {4, 1, 8, 3}};
    Solution sol;
    auto result = sol.minimumTotal(triangle);
    std::cout << result << std::endl;
}
