//
// Created by kayxhding on 2020-05-08 22:54:43
//

/*
   Given a set of candidate numbers (candidates) (without duplicates) and a
target number (target), find all unique combinations in candidates where the
candidate numbers sums to target.

The same repeated number may be chosen from candidates unlimited number of
times.

Note:

All numbers (including target) will be positive integers.
The solution set must not contain duplicate combinations.
Example 1:

Input: candidates = [2,3,6,7], target = 7,
A solution set is:
[
  [7],
  [2,2,3]
]
Example 2:

Input: candidates = [2,3,5], target = 8,
A solution set is:
[
  [2,2,2,2],
  [2,3,3],
  [3,5]
]
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  /*
  回溯法+剪枝
  思路：根据示例 1：输入: candidates = [2,3,6,7]，target = 7。
  候选数组里有 2 ，如果找到了 7 - 2 = 5 的所有组合，再在之前加上 2 ，就是 7
  的所有组合； 同理考虑 3，如果找到了 7 - 3 = 4 的所有组合，再在之前加上 3
  ，就是 7 的所有组合，依次这样找下去；

  复杂度：
  时间复杂度O(2^n)
  空间复杂度 O(2^n)
*/
  vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
    vector<vector<int>> result;
    vector<int> path;
    dfs(candidates, target, 0, path, result);
    return result;
  }

  void dfs(vector<int> &candidates, int gap, int begin, vector<int> &path,
           vector<vector<int>> &result) {
    if (0 == gap) {
      result.push_back(path);
      return;
    }

    for (int i = begin; i < candidates.size(); ++i) {
      if (gap - candidates[i] < 0) {
        break;
      }

      path.push_back(candidates[i]);
      // begin 为i，是因为这里元素可以重复
      dfs(candidates, gap - candidates[i], i, path, result);
      path.pop_back();
    }
  }
};

int main() {
  vector<int> candidates = {2, 3, 5};
  Solution sol;
  auto result = sol.combinationSum(candidates, 8);
  for (auto &v : result) {
    for (auto &e : v) {
      cout << e << " ";
    }
    cout << endl;
  }

  cout << endl;
}
