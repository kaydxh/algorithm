//
// Created by kayxhding on 2020-08-12 22:07:30
//

/*
   Given a non-negative integer numRows, generate the first numRows of Pascal's
triangle.


In Pascal's triangle, each number is the sum of the two numbers directly above
it.

Example:

Input: 5
Output:
[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]

*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<vector<int>> generate(int numRows) {
    vector<vector<int>> result;
    for (int i = 0; i < numRows; ++i) {
      vector<int> rows(i + 1, 0);
      for (int j = 0; j < rows.size(); ++j) {
        if (j == 0 || j == rows.size() - 1) {
          rows[j] = 1;
        } else {
          rows[j] = result[i - 1][j - 1] + result[i - 1][j];
        }
      }

      result.push_back(rows);
    }

    return result;
  }
};

int main() {
  Solution sol;
  auto result = sol.generate(5);
  for (int i = 0; i < result.size(); ++i) {
    for (int j = 0; j < result[i].size(); ++j) {
      std::cout << result[i][j] << " ";
    }
    std::cout << endl;
  }
}
