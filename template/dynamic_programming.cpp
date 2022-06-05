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
 *   // 一般组合问题，需要嵌套循环, 例如整数分割，
 *    for (int j = 0; j < i; ++j)
 *
 *  }
 *   return dp[nums.size()-] - 1
 */

#include <iostream>
#include <vector>
using namespace std;

/*
 * https://leetcode.cn/problems/jump-game-ii/
 * 1. dp[i] 表示到i位置至少需要多少跳, curPos为当前位置，初始值为0
 * 2. 如果cur_pos位置中，最大跳跃距离>= i -  curpos, 就更新dp[i] =
 *    dp[cur_pos] + 1
 * 3. 否则，需要移动curpos， 对下一个cur_pos，在判断能否达到i -
 *    cur_pos位置（注意这里i不需要增加）
 *  时间复杂度O(n)
 *  空间复杂度O(n)
 */
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
 * https://leetcode.cn/problems/partition-equal-subset-sum/solution/fen-ge-deng-he-zi-ji-by-leetcode-solution/
 * 选与不选问题
 * dp[i][j],表示从位置0-i，是否能够组合为和为j
 * 如果不选取 nums[i], dp[i][j]=dp[i−1][j]
 * 如果选取 nums[i], dp[i][j]=dp[i−1][j - nums[i]],   (j - nums[i] >= 0)
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

/*
 * https://leetcode.cn/problems/integer-break/
 * dp[i] 表示：整数i，拆分后的整数(至少2个)最大乘积
 * (i -j) * j，将整数i拆分为i-j 和j, 不再继续拆分
 * dp[i - j] * j, 将整数拆分为i-j 和j, i-j将继续拆分
 * dp[i] = max(dp[i], max(dp[i - j] * j, (i - j) * j));
 * 时间复杂度：O(n^2)
 * 空间复杂度：O(n)
 */
int integerBreak(int n) {
    vector<int> dp(n + 1);
    if (n < 2) {
        return n;
    }

    dp[2] = 1;
    for (int i = 3; i <= n; ++i) {
        for (int j = 1; j < i; ++j) {
            // (i -j) * j，将整数i拆分为i-j 和j, 不再继续拆分
            //  dp[i - j] * j, 将整数拆分为i-j 和j, i-j将继续拆分
            dp[i] = max(dp[i], max(dp[i - j] * j, (i - j) * j));
        }
    }

    return dp[n];
}
