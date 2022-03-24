/*
Given an array of non-negative integers nums, you are initially positioned at
the first index of the array.

Each element in the array represents your maximum jump length at that position.

Your goal is to reach the last index in the minimum number of jumps.

You can assume that you can always reach the last index.

 

Example 1:

Input: nums = [2,3,1,1,4]
Output: 2
Explanation: The minimum number of jumps to reach the last index is 2. Jump 1
step from index 0 to 1, then 3 steps to the last index. Example 2:

Input: nums = [2,3,0,1,4]
Output: 2
 

Constraints:

1 <= nums.length <= 104
0 <= nums[i] <= 1000

*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    /*
     *动态规划：
     1. dp[i] 表示到i位置至少需要多少跳, curPos
     为当前位置，初始值为0
     2. 如果cur_pos位置中，最大跳跃距离>= i -  curpos, 就更新dp[i] =
     dp[cur_pos] + 1
     3. 否则，需要移动curpos， 对下一个cur_pos，在判断能否达到i -
     cur_pos位置（注意这里i不需要增加）
     时间复杂度O(n)
     空间复杂度O(n)
     */
    int jump(vector<int>& nums) {
        int curPos = 0;
        vector<int> dp(nums.size());
        dp[0] = 0;
        for (int i = 1; i < nums.size(); ++i) {
            if (i - curPos <= nums[curPos]) {
                dp[i] = dp[curPos] + 1;
                i++;
            } else {
                curPos++;
            }
        }

        return dp[nums.size() - 1];
    }
};

int main() {
    Solution sol;
    vector<int> nums = {2, 3, 1, 1, 4};
    auto result = sol.jump(nums);
    std::cout << result << std::endl;
}
