//
// Created by kayxhding on 2020-06-18 10:14:59
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  /*
 快慢指针
 1. 慢指针left起始位置0， 快指针right起始位置1，
 count记当前数字出现次数，初始值为1
 2. 快指针遍历数组，若nums[left] !=
 nums[right],则慢指针右移一位，之后，将快指针指向的值赋值给慢指针的位置，
     count计数恢复1
 3. 若nums[left] == nums[right],且 小于最大出现次数2， 则++left, ++count
 4. 否则 nums[left] != nums[right]， 慢指针保持不变，快指针再循环里继续++，右移
 复杂度：
 1. 时间复杂度：O(n)
 2. 空间复杂度: O(1)
*/
  int removeDuplicates(vector<int>& nums) {
    int left = 0;
    int right = 1;
    int count = 1;
    for (; right < nums.size(); ++right) {
      if (nums[left] != nums[right]) {
        ++left;
        nums[left] = nums[right];
        ++count;
      } else {
        if (count < 2) {
          ++left;
          nums[left] = nums[right];
          ++count;
        }
      }
    }

    return left + 1;
  }

#if 0
  int removeDuplicates(vector<int>& nums) {
    int left = 0;
    int right = 0;
    int len = nums.size();
    while (right < nums.size()) {
      if (nums[left] == nums[right]) {
        while (right < nums.size() && nums[left] == nums[right]) {
          cout << "left: " << left << ", right: " << right << endl;
          ++right;
        }

        if (right - left > 1) {
          left += 2;
          // len -= (right - left);
          cout << "--right: " << right << ", left: " << left << endl;
          cout << "len: " << len << endl;
          int i = left;
          int j = right;
          if (left == nums.size() - 1) {
            return left;
          }
          while (j < nums.size()) {
            --len;
            swap(nums[i], nums[j]);
            cout << "i: " << i << ",j: " << j << endl;
            ++i;
            ++j;
          }
        }
      } else {
        ++left;
        ++right;
      }
    }

    return len;
  }
#endif
};

int main() {
  // vector<int> nums = {0, 1, 2, 2, 2, 2, 2, 3, 4, 4, 4};
  vector<int> nums = {2, 2, 2};
  Solution sol;
  auto len = sol.removeDuplicates(nums);
  for (int i = 0; i < len; ++i) {
    cout << nums[i] << " ";
  }
  cout << endl;
}
