//
// Created by kayxhding on 2020-06-15 08:37:45
//

/*
   Given an array with n objects colored red, white or blue, sort them
in-place so that objects of the same color are adjacent, with the colors in the
order red, white and blue.

Here, we will use the integers 0, 1, and 2 to represent the color red, white,
and blue respectively.

Note: You are not suppose to use the library's sort function for this problem.

Example:

Input: [2,0,2,1,1,0]
Output: [0,0,1,1,2,2]
Follow up:

A rather straight forward solution is a two-pass algorithm using counting sort.
First, iterate the array counting number of 0's, 1's, and 2's, then overwrite
array with total number of 0's, then 1's and followed by 2's. Could you come up
with a one-pass algorithm using only constant space?

*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  /*
   快速排序划分
   思路：
   （1）定义三个指针，一个前指针begin，一个中指针current，一个后指针end。current指针遍历整个数组序列。
   （2）当current指针所指元素为0时，与begin指针所指的元素交换，而后current++,begin++
   （3）当current指针所指元素为1时，不做任何交换，只需current右移，即current++
   （4）当current指针所指元素为2时，与end指针所指的元素交换，而后current指针不动（因为如果交换后，current指向0，那么这个0还要和begin交换，所以不必移动），end--

   复杂度：
   时间复杂度：O(n)
   空间复杂度：O(1)
 */
  void sortColors(vector<int> &nums) {
    int begin = 0;
    int current = 0;
    int end = nums.size() - 1;
    while (current <= end) {
      if (nums[current] == 0) {
        swap(nums[begin], nums[current]);
        ++begin;
        ++current;
      } else if (nums[current] == 1) {
        ++current;
      } else {
        swap(nums[current], nums[end]);
        --end;
      }
    }
  }
};

int main() {
  vector<int> nums = {2, 0, 2, 1, 1, 0};
  Solution sol;
  sol.sortColors(nums);
  for (auto &e : nums) {
    cout << e << " ";
  }
  cout << endl;
}
