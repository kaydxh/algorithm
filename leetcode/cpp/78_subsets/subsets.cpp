//
// Created by kayxhding on 2020-06-17 22:46:47
//

/*
 Given a set of distinct integers, nums, return all possible subsets (the power
set).

Note: The solution set must not contain duplicate subsets.

Example:

Input: nums = [1,2,3]
Output:
[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]

*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  /*
回溯法
1. 添加一个数
2. 递归
3. 删除之前的数
4. 下次循环
时间复杂度O(N * 2^N)，生成所有子集，并复制到输出集合中。
空间复杂度：O(N * 2^N)，存储所有子集，共 nn
个元素，每个元素都有可能存在或者不存在
*/
  vector<vector<int>> subsets(vector<int> &nums) {
    vector<vector<int>> result;
    vector<int> path;
    dfs(nums, nums.size(), 0, path, result);
    return result;
  }

  void dfs(vector<int> &nums, int gap, int begin, vector<int> &path,
           vector<vector<int>> &result) {
    if (gap >= 0 && gap <= nums.size()) {
      result.push_back(path);
    } else if (gap < 0) {
      return;
    }

    for (int i = begin; i < nums.size(); ++i) {
      path.push_back(nums[i]);
      dfs(nums, gap - 1, i + 1, path, result);
      path.pop_back();
    }
  }
};

int main() {
  vector<int> nums = {1, 2, 3};
  Solution sol;
  auto result = sol.subsets(nums);
  for (auto &v : result) {
    for (auto &e : v) {
      cout << e << " ";
    }
    cout << endl;
  }
}
