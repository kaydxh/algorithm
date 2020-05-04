//
// Created by kayxhding on 2020-05-04 12:52:00
//

/*
Implement next permutation, which rearranges numbers into the lexicographically
next greater permutation of numbers.

If such arrangement is not possible, it must rearrange it as the lowest possible
order (ie, sorted in ascending order).

The replacement must be in-place and use only constant extra memory.

Here are some examples. Inputs are in the left-hand column and its corresponding
outputs are in the right-hand column.

1,2,3 → 1,3,2
3,2,1 → 1,2,3
1,1,5 → 1,5,1
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  /*
  字典序排列
  思路：假定字符串AxB，它的下一个排序是AyB'，其中A、B和B‘是字符串（可能为空），x和y是字符，前缀相同都是A，且一定有y>x。那么为了是下一个排列字典序尽肯能小，必有：A尽可能长，y尽量小，最后B’的字符按照由小到大递增排列。

  算法的步骤（二找，一交换，一翻转）：
  1. 找到排列中的最后（最右）一个升序的首位位置i，x = ai
  2. 找到排列中第i位右边最后一个比ai大的位置j，y = aj
  3. 交换x和y
  4.
  把第i+1位到最后的部分翻转（执行此步骤前，因为第i位是最后一个升序的位置，所以从i+1到n一定是降序排列的，而执行此步骤后，从i+1到n变成升序排列）

  复杂度分析
  时间复杂度：O(n)，在最坏的情况下，只需要对整个数组进行两次扫描。
  空间复杂度：O(1)，没有使用额外的空间，原地替换足以做到。
*/
  void nextPermutation(vector<int>& nums) {
    int n = nums.size();
    int i = n - 2;
    for (; i >= 0 && nums[i] >= nums[i + 1]; ++i) {
      ;
    }

    if (i >= 0) {
      int j = n - 1;
      for (; j > i && nums[j] <= nums[i]; --j) {
        ;
      }

      swap(nums[i], nums[j]);
    }

    int from = i + 1;
    int to = n - 1;
    while (from < to) {
      int tmp = nums[from];
      nums[from++] = nums[to];
      nums[to--] = tmp;
    }

    return;
  }
};

int main() {
  vector<int> nums = {1, 2, 3};

  Solution sol;
  sol.nextPermutation(nums);
  for (auto& e : nums) {
    cout << e << " ";
  }

  cout << endl;
}
