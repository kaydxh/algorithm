/*
 Given a non-empty array nums containing only positive integers, find if the
array can be partitioned into two subsets such that the sum of elements in both
subsets is equal. Example 1:

Input: nums = [1,5,11,5]
Output: true
Explanation: The array can be partitioned as [1, 5, 5] and [11].
Example 2:

Input: nums = [1,2,3,5]
Output: false
Explanation: The array cannot be partitioned into equal sum subsets.
 

Constraints:

1 <= nums.length <= 200
1 <= nums[i] <= 100
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    /*
     * 动态规划：
     * dp[i][j]表示从区间【0-i]挑选若干个整数，每个整数最多只能用1次，
     * 使得这些数的和为j
     * 状态转移方程：
     * 1. nums[i]不挑选
     * dp [i][j] = dp[i-1][j];
     * 2. nums[i] 挑选
     *  nums[i] == j => dp[i][j]=true
     *  j - nums[i] > 0 => dp[i][j] = dp[i-1][j] || dp[i][j-nums[i]]
     *  时间复杂度：O(NC)：这里 N 是数组元素的个数，C
是数组元素的和的一半。 空间复杂度：O(NC)。
     *
     */
    bool canPartition(vector<int>& nums) {
        if (nums.empty()) {
            return false;
        }
        int sum = 0;
        for (int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
        }

        if ((sum & 1) == 1) {
            return false;
        }
        int target = sum / 2;
        // 需要等于target，所以大小为target+1
        vector<vector<int>> dp(nums.size(), vector<int>(target + 1));

        //初始条件
        if (nums[0] <= target) {
            dp[0][nums[0]] = true;
        }

        for (int i = 1; i < nums.size(); ++i) {
            for (int j = 0; j <= target; ++j) {
                dp[i][j] = dp[i - 1][j];
                if (nums[i] == target) {
                    dp[i][j] = true;
                    continue;
                }

                if (j - nums[i] > 0) {
                    dp[i][j] = dp[i - 1][j] || dp[i - 1][j - nums[i]];
                }
            }
        }

        return dp[nums.size() - 1][target];
    }
};

int main() {
    vector<int> nums = {1, 5, 11, 5};
    Solution sol;
    auto result = sol.canPartition(nums);
    cout << result << endl;
}
