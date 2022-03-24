//
// Created by kayxhding on 2020-05-23 20:32:56
//
/*
   Given an integer array nums, find the contiguous subarray (containing at
least one number) which has the largest sum and return its sum.

Example:

Input: [-2,1,-3,4,-1,2,1,-5,4],
Output: 6
Explanation: [4,-1,2,1] has the largest sum = 6.
Follow up:

If you have figured out the O(n) solution, try coding another solution using the
divide and conquer approach, which is more subtle.

*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    /*
  动态规划
  扫描到第i个元素时，对于i元素有两个选择，要么放入前面找到的子数组，要么作为新子数组的第一个元素：如
  sum >= 0,就认为a[i]放入了前面找到的子数组中，如果sum < 0,
  就认为a[i]是新字数组的开始

  复杂度：
  时间复杂度：O(n)
  空间复杂度：O(1)

  */
    /*
 int maxSubArray(vector<int>& nums) {
   if (nums.empty()) {
     return 0;
   }

   int max_sum = nums[0];
   int sum = 0;

   for (auto i = 0; i < nums.size(); ++i) {
     sum += nums[i];
     if (sum > max_sum) {
       max_sum = sum;
     }
     if (sum < 0) {
       sum = 0;
     }
   }

   return max_sum;
 }
 */

    /*
     *动态规划
     * dp[i]:表示以nums【i]结束的最大子序列和，
     * dp[i] = max(dp[i-1]+nums[i], nums[i]), 即如果dp[i-1] < 0就舍弃
     * 令dp[i]为sum
      复杂度：
      时间复杂度：O(n)
      空间复杂度：O(1)
     */

    int maxSubArray(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }

        int maxSum = nums[0];
        int sum = 0;
        for (auto i = 0; i < nums.size(); ++i) {
            sum = max(sum + nums[i], nums[i]);
            if (sum > maxSum) {
                maxSum = sum;
            }
        }

        return maxSum;
    }
};

int main() {
    // vector<int> nums = {-3, -2, 0, -1};
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    Solution sol;
    auto result = sol.maxSubArray(nums);
    cout << result << endl;
}
