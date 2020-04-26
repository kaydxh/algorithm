//
// Created by kayxhding on 2020-04-26 22:18:23
//

/*
   Given a sorted array nums, remove the duplicates in-place such that each
element appear only once and return the new length.

Do not allocate extra space for another array, you must do this by modifying the
input array in-place with O(1) extra memory.

Example 1:

Given nums = [1,1,2],

Your function should return length = 2, with the first two elements of nums
being 1 and 2 respectively.

It doesn't matter what you leave beyond the returned length.
Example 2:

Given nums = [0,0,1,1,1,2,2,3,3,4],

Your function should return length = 5, with the first five elements of nums
being modified to 0, 1, 2, 3, and 4 respectively.

It doesn't matter what values are set beyond the returned length.
Clarification:

Confused why the returned value is an integer but your answer is an array?

Note that the input array is passed in by reference, which means modification to
the input array will be known to the caller as well.

Internally you can think of this:

// nums is passed in by reference. (i.e., without making a copy)
int len = removeDuplicates(nums);

// any modification to nums in your function would be known by the caller.
// using the length returned by your function, it prints the first len elements.
for (int i = 0; i < len; i++) {
    print(nums[i]);
}
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
  /*
  双指针法
  1. 放置两个指针 i 和 j，其中 i 是慢指针，而 j 是快指针
  2. 如果 nums[i] = nums[j]，就增加 j 以跳过重复项
  3. 否则nums[++i] = nums[j]，将num[j]覆盖到num[++i]位置
  4. 数组长度为i+1

  复杂度分析
  时间复杂度：O(n)，假设数组的长度是 n，那么 i 和 j 分别最多遍历 n步。
  空间复杂度：O(1)。
*/

 public:
  int removeDuplicates(vector<int>& nums) {
    if (nums.size() <= 1) {
      return nums.size();
    }

    int i = 0;
    for (int j = 1; j < nums.size(); ++j) {
      if (nums[i] != nums[j]) {
        nums[++i] = nums[j];
      }
    }

    return i + 1;
  }
};

int main() {
  vector<int> nums = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
  Solution sol;
  auto len = sol.removeDuplicates(nums);
  for (auto i = 0; i < len; ++i) {
    cout << nums[i] << " ";
  }
  cout << endl;
}
