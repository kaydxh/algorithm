//
// Created by kayxhding on 2020-04-19 17:11:41
//

/*
   Given an array nums of n integers and an integer target, find three integers
in nums such that the sum is closest to target. Return the sum of the three
integers. You may assume that each input would have exactly one solution.

Example:

Given array nums = [-1, 2, 1, -4], and target = 1.

The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).

*/

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  /*
  思路：排序+双指针法
  1. 对数组进行排序
  2. 遍历current 从 0 ～ nums.size() - 1
  3. low指针指向index 为1， high指向nums.size() - 1
  4. sum = nums[current] + nums[low] + nums[high],
    如果 sum = target,返回sum，如果，sum < target, ++low,否则 --high

  复杂度：
  1. 时间复杂度O(n2)
  2. 空间复杂度O(1)
*/
  int threeSumClosest(vector<int>& nums, int target) {
    if (nums.size() < 3) {
      return 0;
    }

    sort(nums.begin(), nums.end());

    int result = nums[0] + nums[1] + nums[2];
    int closestValue = abs(target - result);
    int sum = 0;
    for (auto current = 0; current < nums.size() - 2; ++current) {
      int low = current + 1;
      int high = nums.size() - 1;

      while (low < high) {
        sum = nums[current] + nums[low] + nums[high];
        if (sum == target) {
          return sum;
        } else if (sum < target) {
          ++low;
        } else {
          --high;
        }

        if (abs(target - sum) < closestValue) {
          closestValue = abs(target - sum);
          result = sum;
        }
      }
    }
    return result;
  }
};

int main() {
  vector<int> nums = {-1, 2, 1, -4};
  Solution sol;
  auto result = sol.threeSumClosest(nums, 1);
  cout << result << endl;
}
