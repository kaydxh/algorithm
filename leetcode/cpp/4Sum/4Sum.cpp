//
// Created by kayxhding on 2020-04-12 16:32:28
//

/*
 Given an array nums of n integers and an integer target, are there elements
a, b, c, and d in nums such that a + b + c + d = target? Find all unique
quadruplets in the array which gives the sum of target.

Note:

The solution set must not contain duplicate quadruplets.

Example:

Given array nums = [1, 0, -1, 0, -2, 2], and target = 0.

A solution set is:
[
  [-1,  0, 0, 1],
  [-2, -1, 1, 2],
  [-2,  0, 0, 2]
]
*/

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  /**
    1. 先排序
    2. 确定low和pos的最小和最大位置为1和nums.size() -1
    3. 遍历第三个数a,第四个数b，如果 a + b+ nums[high] + nums[high] ==
  target,得解,并开始去重
    4. 如果 a + b+ nums[high] + nums[high] < target, low++
    5. 如果 a + b + nums[high] + nums[high] > target, high--
    6, 对于第三个数a进行去重
    7, 对于第四个数b进行去重
    时间复杂度：O(n^3)
  **/
  vector<vector<int>> fourSum(vector<int>& nums, int target) {
    vector<vector<int>> result;
    sort(nums.begin(), nums.end());
    for (auto i = 0; i < nums.size(); ++i) {
      for (auto j = i + 1; j < nums.size(); ++j) {
        int low = j + 1;
        int high = nums.size() - 1;
        while (low < high) {
          int low_num = nums[low];
          int high_num = nums[high];
          if (nums[i] + nums[j] + nums[low] + nums[high] == target) {
            vector<int> elems = {nums[i], nums[j], nums[low], nums[high]};
            result.push_back(elems);
            //去重，nums[low] == num_low 第一次肯定成立，所以low必定右移一位
            while (low < high && nums[low] == low_num) {
              ++low;
            }
            //去重，ums[high] == num_high 第一次肯定成立，所以high必定左移一位
            while (low < high && nums[high] == high_num) {
              --high;
            }
          } else if (nums[i] + nums[j] + nums[low] + nums[high] < target) {
            ++low;
          } else {
            --high;
          }
        }
        // 对nums[j] 去重
        while (j + 1 < nums.size() && nums[j] == nums[j + 1]) {
          ++j;
        }
      }
      // 对nums[i] 去重
      while (i + 1 < nums.size() && nums[i] == nums[i + 1]) {
        ++i;
      }
    }

    return result;
  }
};

int main() {
  vector<int> nums = {1, 0, -1, 0, -2, 2};
  int target = 0;
  Solution sol;
  auto result = sol.fourSum(nums, target);
  for (auto i = 0; i < result.size(); ++i) {
    for (auto j = 0; j < result[i].size(); ++j) {
      cout << result[i][j] << " ";
    }
    cout << endl;
  }
}
