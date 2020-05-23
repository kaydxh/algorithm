//
// Created by kayxhding on 2020-05-23 13:18:03
//

/*
   Suppose an array sorted in ascending order is rotated at some pivot unknown
to you beforehand.

(i.e., [0,0,1,2,2,5,6] might become [2,5,6,0,0,1,2]).

You are given a target value to search. If found in the array return true,
otherwise return false.

Example 1:

Input: nums = [2,5,6,0,0,1,2], target = 0
Output: true
Example 2:

Input: nums = [2,5,6,0,0,1,2], target = 3
Output: false
Follow up:

This is a follow up problem to Search in Rotated Sorted Array, where nums may
contain duplicates. Would this affect the run-time complexity? How and why?

*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
  /*
  1. 求数组的中间middle的值，如果等于target，就返回middle
  2. 去重
  3. 如果nums[0] <
  nums[middle]即有序，且target在nums[0]~nums[middle]之间，则right = middle -1,
  否则，left = middle +1
  4. 如过nums[0] >= nums[middle], nums[middle+1] ~ nums[n
  -1]有序，且target在nums[middle]~ nums[n - 1]
  之间，那么left=middle+1，否则right = middle - 1

  复杂度：
  时间复杂度： O(logn)
  空间复杂度： O(1) 。我们只需要常数级别的空间存放变量。
*/
 public:
  bool search(vector<int>& nums, int target) {
    int left = 0;
    int right = nums.size() - 1;
    while (left <= right) {
      int middle = left + (right - left) / 2;
      if (nums[middle] == target) {
        return true;
      }

      //去重
      if (nums[left] == nums[middle]) {
        ++left;
        continue;
      }

      //前半部分有序
      if (nums[0] < nums[middle]) {
        // target在前半部分
        if (nums[middle] > target && nums[0] <= target) {
          right = middle - 1;
        } else {
          //否则，去后半部分找
          left = middle + 1;
        }
      } else {
        //后半部分有序
        // target在后半部分
        if (nums[middle] < target && nums[nums.size() - 1] >= target) {
          left = middle + 1;
        } else {
          //否则，去前半部分找
          right = middle - 1;
        }
      }
    }

    return false;
  }
};

int main() {
  vector<int> nums = {1, 3, 1, 1, 1};
  Solution sol;
  auto result = sol.search(nums, 3);
  cout << result << endl;
}
