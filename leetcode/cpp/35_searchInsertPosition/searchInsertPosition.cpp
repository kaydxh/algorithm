//
// Created by kayxhding on 2020-05-07 09:39:18
//
/*
Given a sorted array and a target value, return the index if the target is
found. If not, return the index where it would be if it were inserted in order.

You may assume no duplicates in the array.

Example 1:

Input: [1,3,5,6], 5
Output: 2
Example 2:

Input: [1,3,5,6], 2
Output: 1
Example 3:

Input: [1,3,5,6], 7
Output: 4
Example 4:

Input: [1,3,5,6], 0
Output: 0

*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  int searchInsert(vector<int>& nums, int target) {
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
        return middle;
      }
    }

    return left;
  }
};

int main() {
  vector<int> nums = {1, 3, 5, 6};
  Solution sol;
  auto result = sol.searchInsert(nums, 2);
  cout << result << endl;
}
