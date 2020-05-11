//
// Created by kayxhding on 2020-05-11 22:46:11
//

/*
 Given a collection of candidate numbers (candidates) and a target number
(target), find all unique combinations in candidates where the candidate numbers
sums to target.

Each number in candidates may only be used once in the combination.

Note:

All numbers (including target) will be positive integers.
The solution set must not contain duplicate combinations.
Example 1:

Input: candidates = [10,1,2,7,6,1,5], target = 8,
A solution set is:
[
  [1, 7],
  [1, 2, 5],
  [2, 6],
  [1, 1, 6]
]
Example 2:

Input: candidates = [2,5,2,1,2], target = 5,
A solution set is:
[
  [1,2,2],
  [5]
]
*/

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<vector<int>> combinationSum2(vector<int> &candidates, int target) {
    vector<vector<int>> result;
    vector<int> path;
    sort(candidates.begin(), candidates.end());
    dfs(candidates, target, 0, path, result);

    return result;
  }

  void dfs(vector<int> &candidates, int gap, int begin, vector<int> &path,
           vector<vector<int>> &result) {
    if (0 == gap) {
      result.push_back(path);
      return;
    }

    for (auto i = begin; i < candidates.size(); ++i) {
      if (gap - candidates[i] < 0) {
        break;
      }

      if (i > begin && candidates[i] == candidates[i - 1]) {
        continue;
      }

      path.push_back(candidates[i]);
      dfs(candidates, gap - candidates[i], i + 1, path, result);
      path.pop_back();
    }
  }
};

int main() {
  vector<int> candidates = {10, 1, 2, 7, 6, 1, 5};
  Solution sol;
  auto result = sol.combinationSum2(candidates, 8);
  for (auto &v : result) {
    for (auto &e : v) {
      cout << e << " ";
    }
    cout << endl;
  }
  cout << endl;
}
