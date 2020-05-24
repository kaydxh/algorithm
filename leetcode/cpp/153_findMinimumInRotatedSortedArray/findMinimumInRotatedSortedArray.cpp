//
// Created by kayxhding on 2020-05-23 13:57:34
//

/*
   Suppose an array sorted in ascending order is rotated at some pivot unknown
to you beforehand.

(i.e.,  [0,1,2,4,5,6,7] might become  [4,5,6,7,0,1,2]).

Find the minimum element.

You may assume no duplicate exists in the array.

Example 1:

Input: [3,4,5,1,2]
Output: 1
Example 2:

Input: [4,5,6,7,0,1,2]
Output: 0
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  /*
  1 有序数组分成了左右2个小的有序数组，而实际上要找的是右边有序数组的最小值
  2 如果中间值大于右边的最大值，说明中间值还在左边的小数组里，需要更新left =
  middle + 1 3 否则就是中间值小于等于当前右边最大值，mid
  已经在右边的小数组里了，但是至少说明了当前右边的right值不是最小值了或者不是唯一的最小值，需要慢慢向左移到middle。
  4. 主要这里因为right = num.size() - 1, 本来while（left <=
  right）,因为3里right=middle，所以为了避免死循环，改为while(left <
  right)，例子[3,1,2]

  复杂度：
  时间复杂度：O(logn)
  空间复杂度：O(1)
*/
  int findMin(vector<int>& nums) {
    int left = 0;
    int right = nums.size() - 1;
    while (left < right) {
      int middle = left + (right - left) / 2;
      if (nums[middle] > nums[right]) {
        left = middle + 1;
      } else {
        right = middle;
      }
    }

    return nums[left];
  }
};

int main() {
  vector<int> nums = {3, 1, 2};
  Solution sol;
  auto result = sol.findMin(nums);
  cout << result << endl;
}
