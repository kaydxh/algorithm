//
// Created by kayxhding on 2020-05-23 21:46:47
//

/*
   Given an integer array nums, find the contiguous subarray within an array
(containing at least one number) which has the largest product.

Example 1:

Input: [2,3,-2,4]
Output: 6
Explanation: [2,3] has the largest product 6.
Example 2:

Input: [-2,0,-1]
Output: 0
Explanation: The result cannot be 2, because [-2,-1] is not a subarray.

*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  /*
动态规划：
先定义一个数组 dpMax，用 dpMax[i] 表示以第 i
个元素的结尾的子数组，乘积最大的值，也就是这个数组必须包含第 i 个元素。

那么 dpMax[i] 的话有几种取值。

当 nums[i] >= 0 并且dpMax[i-1] > 0，dpMax[i] = dpMax[i-1] * nums[i]
当 nums[i] >= 0 并且dpMax[i-1] <
0，此时如果和前边的数累乘的话，会变成负数，所以dpMax[i] = nums[i] 当 nums[i] <
0，此时如果前边累乘结果是一个很大的负数，和当前负数累乘的话就会变成一个更大的数。所以我们还需要一个数组
dpMin 来记录以第 i 个元素的结尾的子数组，乘积最小的值。 当dpMin[i-1] <
0，dpMax[i] = dpMin[i-1] * nums[i] 当dpMin[i-1] >= 0，dpMax[i] = nums[i]
1. dpMax[i] 的取值无非就是三种，dpMax[i-1] * nums[i]、dpMin[i-1] * nums[i] 以及
nums[i]。
2. dpMin[i] 同理, dpMin[i] = min(dpMax[i-1] * nums[i], dpMin[i-1] * nums[i],
nums[i]);

复杂度：
时间复杂度O(n)
*/
  int maxProduct(vector<int>& nums) {
    int n = nums.size();
    if (n == 0) {
      return 0;
    }

    int dpMax = nums[0];
    int dpMin = nums[0];
    int product_max = nums[0];
    for (int i = 1; i < n; ++i) {
      int predpMax = dpMax;
      dpMax = max(dpMin * nums[i], max(dpMax * nums[i], nums[i]));
      dpMin = min(dpMin * nums[i], min(predpMax * nums[i], nums[i]));
      product_max = max(dpMax, product_max);
    }

    return product_max;
  }
};

int main() {
  vector<int> nums = {-1, -2, -9, -6};
  Solution sol;
  auto result = sol.maxProduct(nums);
  cout << result << endl;
}
