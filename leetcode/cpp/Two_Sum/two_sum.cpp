//
// Created by kayxhding on 2020-04-11 22:46:15
//

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
        result.push_back(i);
        result.push_back(it->second);
        return result;
      }
      //注意，这里更新map需要放在查询后面，这样可以避免相同元素在查询前就更新了map，导致没有得到查询机会，如
      //nums={3,3}，target为6时
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
