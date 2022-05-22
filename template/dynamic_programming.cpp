/*
 * 动态规划：
 * 1. 怎么知道这个问题可以用动态规划解决
 *    问题能否缩小为子问题解决, 子问题依赖先前的计算结果
 * 2. 确定问题变量
 *   dp[i] 或者 dp[i][j] 含义
 * 3. 定义状态转移方程
 *    + dp[i] = dp[i-1] ...
 *    + 放 or 不放
        dp[i][j] = dp[i - 1][j] || dp[i - 1][j - nums[i]];
 *
 * 4. 确定基本case
 *   dp[0]
 * 5. 遍历迭代
 *  for (int i = 1; i < nums.size(); ++i) {
 *   //根据状态方式写逻辑
 *
 *  }
 *   return dp[nums.size()-] - 1
 */

#include <iostream>
#include <vector>
using namespace std;

int dynamic(vector<int> &nums) {
    int curPos = 0;
    vector<int> dp(nums.size());
    dp[0] = 0;
    for (int i = 1; i < nums.size(); ++i) {
        if (i - curPos <= nums[curPos]) {
            dp[i] = dp[curPos] + 1;
        } else {
            curPos++;
        }
    }

    return dp[nums.size() - 1];
}

/*
 * 选与不选问题
 * dp[i][j]
 */
bool partition(vector<int> &nums, int target) {
    if (nums.empty()) {
        return false;
    }
    vector<vector<int>> dp(nums.size(), vector<int>(target + 1));
    //二维数组大小为 nums.size(), target+1
    if (nums[0] <= target) {
        dp[0][nums[0]] = true;
    }
    for (int i = 1; i < nums.size(); ++i) {
        for (int j = 0; j <= target; ++j) {
            if (nums[i] == target) {
                dp[i][j] = true;
                continue;
            }

            // 默认不选, 当j - nums[i] < 0时， 只能不选择位置j
            dp[i][j] = dp[i - 1][j];
            // 二维数组索引需要满足>= 0
            if (j - nums[i] >= 0) {
                dp[i][j] = dp[i - 1][j] || dp[i - 1][j - nums[i]];  //不选 || 选
            }
        }
    }

    return dp[nums.size() - 1][target];
}
