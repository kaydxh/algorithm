/*
 * Given an integer rowIndex, return the rowIndexth (0-indexed) row of the
Pascal's triangle. In Pascal's triangle, each number is the sum of the two
numbers directly above it as shown:

Example 1:

Input: rowIndex = 3
Output: [1,3,3,1]
Example 2:

Input: rowIndex = 0
Output: [1]
Example 3:

Input: rowIndex = 1
Output: [1,1]
 

Constraints:

0 <= rowIndex <= 33
 

Follow up: Could you optimize your algorithm to use only O(rowIndex) extra
space?

 */
#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    /*
     * 动态规划
     * dp[i][j]代表第行第j列的数字
     * 状态转移方程
     * dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
     * 第一列和最后一列都是1
        复杂度：
        时间复杂度O(n^2)
     */
    vector<int> getRow(int rowIndex) {
        vector<vector<int>> result(rowIndex + 1);
        for (int i = 0; i <= rowIndex; ++i) {
            result[i].resize(i + 1);
            result[i][0] = result[i][i] = 1;
            for (int j = 1; j < i; ++j) {
                result[i][j] = result[i - 1][j] + result[i - 1][j - 1];
            }
        }

        return result[rowIndex];
    }
};

int main() {
    Solution sol;
    auto result = sol.getRow(5);
    for (int i = 0; i < result.size(); ++i) {
        std::cout << result[i] << " ";
    }
}
