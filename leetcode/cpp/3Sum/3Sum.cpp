//
// Created by kayxhding on 2020-04-10 22:48:57
//

/***
Given an array nums of n integers, are there elements a, b, c in nums such
that a + b + c = 0? Find all unique triplets in the array which gives the sum of
zero.

Note:

The solution set must not contain duplicate triplets.

Example:

Given array nums = [-1, 0, 1, 2, -1, -4],

A solution set is:
[
  [-1, 0, 1],
  [-1, -1, 2]
]
***/

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  /**
   1. 先排序
   2. 确定low和pos的最小和最大位置为1和nums.size() -1
   3. 遍历第三个数a，如果 a + nums[high] + nums[high] == 0,得解,并开始去重
   4. 如果 a + nums[high] + nums[high] < 0, low++
   5. 如果 a + nums[high] + nums[high] > 0, high--
   6, 对于第三个数a进行去重
   算法复杂度：O(n^2)
**/
  vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> result;
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size(); ++i) {
      int low = i + 1;
      int high = nums.size() - 1;
      while (low < high) {
        int num_low = nums[low];
        int num_high = nums[high];
        if (nums[i] + num_low + num_high == 0) {
          vector<int> elems = {nums[i], num_low, num_high};
          result.push_back(elems);
          //去重，nums[low] == num_low 第一次肯定成立，所以low必定右移一位
          while (low < high && nums[low] == num_low) {
            ++low;
          }
          //去重，ums[high] == num_high 第一次肯定成立，所以high必定左移一位
          while (low < high && nums[high] == num_high) {
            --high;
          }
        } else if (nums[i] + num_low + num_high < 0) {
          ++low;
        } else {
          --high;
        }
      }
      //去重
      while (i + 1 < nums.size() && nums[i] == nums[i + 1]) {
        ++i;
      }
    }

    return result;
  }
};

int main() {
  Solution sol;
  vector<int> nums = {-1, -0, 1, 2, -1, -4};
  auto result = sol.threeSum(nums);
  for (auto i = 0; i < result.size(); ++i) {
    for (auto j = 0; j < result[i].size(); ++j) {
      cout << result[i][j] << " ";
    }
    cout << endl;
  }
}
