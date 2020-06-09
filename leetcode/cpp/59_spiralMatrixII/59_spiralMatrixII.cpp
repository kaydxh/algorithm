//
// Created by kayxhding on 2020-06-09 22:26:40
//

/*
Given a positive integer n, generate a square matrix filled with elements from 1
to n2 in spiral order.

Example:

Input: 3
Output:
[
 [ 1, 2, 3 ],
 [ 8, 9, 4 ],
 [ 7, 6, 5 ]
]

*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<vector<int>> generateMatrix(int n) {
    vector<vector<int>> result(n, vector<int>(n));
    int top_border = -1;
    int left_border = -1;
    int right_border = n;
    int botttom_border = n;

    int dirction = 0;
    int count = 1;
    int i = 0;
    int j = 0;
    while (true) {
      if (count > n * n) {
        return result;
      }
      result[i][j] = count++;

      switch (dirction) {
        case 0:
          if (j + 1 == right_border) {
            dirction = 1;
            ++top_border;
            ++i;
          } else {
            ++j;
          }

          break;
        case 1:
          if (i + 1 == botttom_border) {
            dirction = 2;
            --right_border;
            --j;
          } else {
            ++i;
          }
          break;
        case 2:
          if (j - 1 == left_border) {
            dirction = 3;
            --botttom_border;
            --i;
          } else {
            --j;
          }
          break;
        case 3:
          if (i - 1 == top_border) {
            dirction = 0;
            ++left_border;
            ++j;
          } else {
            --i;
          }
          break;
        default:
          break;
      }
    }

    return result;
  }
};

int main() {
  Solution sol;
  auto result = sol.generateMatrix(3);
  for (auto i = 0; i < result.size(); ++i) {
    for (auto j = 0; j < result[i].size(); ++j) {
      cout << result[i][j] << " ";
    }
    cout << endl;
  }
}
