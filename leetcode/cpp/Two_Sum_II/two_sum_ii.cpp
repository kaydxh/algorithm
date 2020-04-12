//
// Created by kayxhding on 2020-04-11 22:46:15
//
/*
 Given an array of integers that is already sorted in ascending order, find two
numbers such that they add up to a specific target number.

The function twoSum should return indices of the two numbers such that they add
up to the target, where index1 must be less than index2.

Note:

Your returned answers (both index1 and index2) are not zero-based.
You may assume that each input would have exactly one solution and you may not
use the same element twice. Example:

Input: numbers = [2,7,11,15], target = 9
Output: [1,2]
Explanation: The sum of 2 and 7 is 9. Therefore index1 = 1, index2 = 2.

*/

#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<int> twoSum(vector<int>& nums, int target) {
    vector<int> result;
    unordered_map<int, int> num_index_map;
    //将nums按照key为num的值，value为index进行存储
    // num_index_map 采用unordered_map提高查询速度，O(1)
    for (auto i = 0; i < nums.size(); ++i) {
      auto it = num_index_map.find(target - nums[i]);
      if (it != num_index_map.end() && i != it->second) {
        //索引是从1开始，所以要+1
        //查找到target-nums[i] == nums[j] (j < i，num[i] >=auto it =
        //num_index_map.find(target - nums[i]);
        // nums[j]),那么必然得到满足条件的nums[j](即target-nums[i] ),
        // nums[i],其中索引j < i,所以先push it->sencond+1
        result.push_back(it->second + 1);
        result.push_back(i + 1);
        return result;
      }
      //注意，这里更新map需要放在查询后面，这样可以避免相同元素在查询前就更新了map，导致没有得到查询机会，如
      // nums={3,3}，target为6时
      num_index_map[nums[i]] = i;
    }
#if 0
    for (auto i = 0; i < nums.size(); ++i) {
      auto it = num_index_map.find(target - nums[i]);
      if (it != num_index_map.end() && i != it->second) {
        result.push_back(i);
        result.push_back(it->second);
        return result;
      }
    }
#endif
    return result;
  }
};

int main() {
  vector<int> nums = {2, 7, 11, 15};
  int target = 9;
  Solution sol;
  auto result = sol.twoSum(nums, target);
  for (auto i = 0; i < result.size(); ++i) {
    cout << result[i] << " ";
  }
  cout << endl;
}
