//
// Created by kayxhding on 2020-05-05 22:51:13
//
/*

Suppose an array sorted in ascending order is rotated at some pivot unknown to
you beforehand.

(i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]).

You are given a target value to search. If found in the array return its index,
otherwise return -1.

You may assume no duplicate exists in the array.

Your algorithm's runtime complexity must be in the order of O(log n).

Example 1:

Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4
Example 2:

Input: nums = [4,5,6,7,0,1,2], target = 3
Output: -1
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  /*
  二分搜索
  在常规二分搜索的时候查看当前 mid 为分割位置分割出来的两个部分 [l, mid] 和 [mid
  + 1, r]
  哪个部分是有序的，并根据有序的那个部分确定我们该如何改变二分搜索的上下界

  1. 求数组的中间middle的值，如果等于target，就返回middle
  2. 如果nums[0] <=
  nums[middle]即有序，且target在nums[0]~nums[middle]之间，则right = middle -1,
  否则，left = middle +1
  3. 否则nums[middle+1] ~ nums[n -1]有序，且target在nums[middle]~ nums[n - 1]
  之间，那么left=middle+1，否则right = middle - 1

  复杂度：
  时间复杂度： O(logn)
  空间复杂度： O(1) 。我们只需要常数级别的空间存放变量。
*/
  int search(vector<int>& nums, int target) {
    int n = nums.size();
    int left = 0;
    int right = n - 1;

    while (left <= right) {
      int middle = (left + right) / 2;
      if (nums[middle] == target) {
        return middle;
      }

      if (nums[0] <= nums[middle]) {
        if (nums[0] <= target && nums[middle] > target) {
          right = middle - 1;
        } else {
          left = middle + 1;
        }
      } else {
        if (nums[middle] < target && nums[n - 1] >= target) {
          left = middle + 1;
        } else {
          right = middle - 1;
        }
      }
    }

    return -1;
  }
};

int main() {
  vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
  Solution sol;
  auto result = sol.search(nums, 4);
  cout << result << endl;
}
