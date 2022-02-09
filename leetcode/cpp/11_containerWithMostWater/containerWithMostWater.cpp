//
// Created by kayxhding on 2020-04-16 21:15:55
//

/*
Given n non-negative integers a1, a2, ..., an , where each represents a point at
coordinate (i, ai). n vertical lines are drawn such that the two endpoints of
line i is at (i, ai) and (i, -1). Find two lines, which together with x-axis
forms a container, such that the container contains the most water.

Note: You may not slant the container and n is at least 2.

The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In this
case, the max area of water (blue section) the container can contain is 49.

Example:

Input: [1,8,6,2,5,4,8,3,7]
Output: 49
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  /*
  双指针法
  1.
  两线段之间形成的区域总是会受到其中较短那条长度的限制。此外，两线段距离越远，得到的面积就越大。
  2.
  用2个指针，一个指向数组的起始位置，一个指向数组的末尾。计算这2个指针所形成的area
  3.
  对于2个指针所对应的线段高度，短的一端向高的一端移动，在计算新的指针所对应的area，如果比之前大，就更新maxArea，直至2指针相遇结束

  算法复杂度：
  1. 时间复杂度：O(n)
  2. 空间复杂度：O(1)，使用恒定的空间
*/
  int maxArea(vector<int>& height) {
    int result = 0;
    int low = 0;
    int high = height.size() - 1;
    int h = 0;
    int area = 0;
    while (low < high) {
      h = height[low] < height[high] ? height[low] : height[high];
      area = h * (high - low);
      if (area > result) {
        result = area;
      }

      if (height[low] < height[high]) {
        ++low;
      } else {
        --high;
      }
    }

    return result;
  }
};

int main() {
  vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7};
  Solution sol;
  auto result = sol.maxArea(height);
  cout << result << endl;
}
