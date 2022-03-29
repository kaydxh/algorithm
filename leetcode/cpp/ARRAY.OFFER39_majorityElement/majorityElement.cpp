/*
 * 数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。
你可以假设数组是非空的，并且给定的数组总是存在多数元素。
示例 1:

输入: [1, 2, 3, 2, 2, 2, 5, 4, 2]
输出: 2

限制：
1 <= 数组长度 <= 50000
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    /*
     * 根据数组的特点，数组中有一个数字出现次数超过数组长度的一半，即它
     * 出现的次数比其他所有数字出现次数的和还要多。
     * 遍历数组，初始化时，选择第一个元素为出现次数最多的元素，计数为1
     * 后续遍历时
     * 1. 如果计数为0，那么当前更新result为当前遍历的元素，计数=1
     * 2. 如果当前元素 == result, 那么计数++， 否则计数--
     * 时间复杂度：O(n)
     * 空间复杂度：O(1)
     */
    int majorityElement(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        int result = nums[0];
        int times = 1;
        for (int i = 1; i < nums.size(); ++i) {
            if (times == 0) {
                result = nums[i];
                times = 1;
            } else if (nums[i] == result) {
                times++;
            } else {
                times--;
            }
        }

        return result;
    }
};

int main() {
    vector<int> nums = {10, 9, 9, 9, 10};
    Solution sol;
    auto result = sol.majorityElement(nums);
    std::cout << result << std::endl;
}
