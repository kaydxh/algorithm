//
// Created by kayxhding on 2020-05-10 21:30:26
//

/*
The set [1,2,3,...,n] contains a total of n! unique permutations.
By listing and labeling all of the permutations in order, we get the following
sequence for n = 3:

"123"
"132"
"213"
"231"
"312"
"321"
Given n and k, return the kth permutation sequence.

Note:

Given n will be between 1 and 9 inclusive.
Given k will be between 1 and n! inclusive.
Example 1:

Input: n = 3, k = 3
Output: "213"
Example 2:

Input: n = 4, k = 9
Output: "2314"
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
 public:
  string getPermutation(int n, int k) {
    string s = string("123456789").substr(0, n);

    vector<int> used(n, 0);
    vector<char> path;
    vector<vector<char>> result;
    vector<int> factorial;
    factorial.resize(n + 1);
    factorial[0] = 1;
    for (int i = 1; i <= n; ++i) {
      factorial[i] = factorial[i - 1] * i;
    }

    --k;
    int firstNum = s[k / factorial[n - 1]] - '0';
    s = s.erase(k / factorial[n - 1], 1);
    k %= factorial[n - 1];
    dfs(s, 0, k + 1, used, factorial, path, result);

    if (result.size() == 0) {
      return to_string(firstNum);
    }

    return to_string(firstNum) + string(result[result.size() - 1].begin(),
                                        result[result.size() - 1].end());
  }

  void dfs(string s, int gap, int k, vector<int> &used, vector<int> &factorial,
           vector<char> &path, vector<vector<char>> &result) {
    if (gap == s.length()) {
      result.push_back(path);
      return;
    }

    for (int i = 0; i < s.length(); ++i) {
      if (result.size() >= k) {
        return;
      }
      if (used[i]) {
        continue;
      }
      path.push_back(s[i]);
      used[i] = true;
      dfs(s, gap + 1, k, used, factorial, path, result);
      path.pop_back();
      used[i] = false;
    }
  }
};

int main() {
  Solution sol;
  auto result = sol.getPermutation(3, 2);
  cout << result << endl;
}
