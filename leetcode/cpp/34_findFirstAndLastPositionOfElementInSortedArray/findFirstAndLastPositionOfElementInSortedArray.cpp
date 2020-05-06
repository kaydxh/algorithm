//
// Created by kayxhding on 2020-05-06 23:21:30
//

/*
   Given an array of integers nums sorted in ascending order, find the starting
and ending position of a given target value.

Your algorithm's runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].

Example 1:

Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]
Example 2:

Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]

*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  /*
因为我们初始化 right = nums.length - 1
所以决定了我们的「搜索区间」是 [left, right]
所以决定了 while (left <= right)
同时也决定了 left = mid+1 和 right = mid-1

因为我们只需找到一个 target 的索引即可
所以当 nums[mid] == target 时可以立即返回

时间复杂度：O(log2n)
空间复杂度：O(1)
*/
  vector<int> searchRange(vector<int>& nums, int target) {
    int start_index = left_bound(nums, target);
    int end_index = right_bound(nums, target);

    return vector<int>{start_index, end_index};
  };

  int left_bound(vector<int>& nums, int target) {
    int n = nums.size();
    int left = 0;
    int right = n - 1;
    while (left <= right) {
      int middle = left + (right - left) / 2;
      if (nums[middle] < target) {
        left = middle + 1;
      } else if (nums[middle] > target) {
        right = middle - 1;
      } else if (nums[middle] == target) {
        right = middle - 1;
      }
    }

    if (left >= n || nums[left] != target) {
      return -1;
    }

    return left;
  }

  int right_bound(vector<int>& nums, int target) {
    int n = nums.size();
    int left = 0;
    int right = n - 1;
    while (left <= right) {
      int middle = left + (right - left) / 2;
      if (nums[middle] < target) {
        left = middle + 1;
      } else if (nums[middle] > target) {
        right = middle - 1;
      } else if (nums[middle] == target) {
        left = middle + 1;
      }
    }

    if (right <= 0 || nums[right] != target) {
      return -1;
    }

    return right;
  }
};

int main() {
  vector<int> nums = {5, 7, 7, 8, 8, 10};
  Solution sol;
  auto result = sol.searchRange(nums, 8);
  for (auto e : result) {
    cout << e << " ";
  }
  cout << endl;
}
