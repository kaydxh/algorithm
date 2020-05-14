//
// Created by kayxhding on 2020-05-13 23:21:50
//

/*
   For a non-negative integer X, the array-form of X is an array of its digits
in left to right order.  For example, if X = 1231, then the array form
is [1,2,3,1].

Given the array-form A of a non-negative integer X, return the array-form of the
integer X+K.

Example 1:

Input: A = [1,2,0,0], K = 34
Output: [1,2,3,4]
Explanation: 1200 + 34 = 1234
Example 2:

Input: A = [2,7,4], K = 181
Output: [4,5,5]
Explanation: 274 + 181 = 455
Example 3:

Input: A = [2,1,5], K = 806
Output: [1,0,2,1]
Explanation: 215 + 806 = 1021
Example 4:

Input: A = [9,9,9,9,9,9,9,9,9,9], K = 1
Output: [1,0,0,0,0,0,0,0,0,0,0]
Explanation: 9999999999 + 1 = 10000000000

Note：

1 <= A.length <= 10000
0 <= A[i] <= 9
0 <= K <= 10000
If A.length > 1, then A[0] != 0

*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<int> addToArrayForm(vector<int>& A, int K) {
    vector<int> result;
    int n = A.size();
    int carry = 0;
    int val1 = 0;
    int val2 = 0;
    for (auto i = n - 1; i >= 0 || K != 0;) {
      if (i < 0) {
        val1 = 0;
      } else {
        val1 = A[i];
        --i;
      }

      if (K == 0) {
        val2 = 0;
      } else {
        val2 = K % 10;
        K /= 10;
      }

      int sum = val1 + val2 + carry;
      carry = sum / 10;
      int digit = sum % 10;
      result.insert(result.begin(), digit);
    }

    if (carry > 0) {
      result.insert(result.begin(), carry);
    }

    return result;
  }
};

int main() {
  vector<int> A = {1, 2, 0, 0};
  Solution sol;
  auto result = sol.addToArrayForm(A, 34);
  for (auto& e : result) {
    cout << e << " ";
  }

  cout << endl;
}
