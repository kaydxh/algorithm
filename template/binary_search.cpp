#include <iostream>
#include <vector>
using namespace std;
/*
 * 二分搜索
 * 1. 定义left、right
 * while (left <= right) 注意有等号
 * 2. 计算middle位置，根据middle位置的值与targe大小，来进行范围缩小：
 * left = middle + 1 / right = middle - 1
 */

int binarySearch(vector<int> &nums, int target) {
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

    return -1;
}

int main() {
    // must ordered array
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8};
    auto result = binarySearch(nums, 4);
    std::cout << result << std::endl;
}
