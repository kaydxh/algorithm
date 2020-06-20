//
// Created by kayxhding on 2020-06-20 21:30:53
//

/*
 The gray code is a binary numeral system where two successive values differ in
only one bit.

Given a non-negative integer n representing the total number of bits in the
code, print the sequence of gray code. A gray code sequence must begin with 0.

Example 1:

Input: 2
Output: [0,1,3,2]
Explanation:
00 - 0
01 - 1
11 - 3
10 - 2

For a given n, a gray code sequence may not be uniquely defined.
For example, [0,2,3,1] is also a valid gray code sequence.

00 - 0
10 - 2
11 - 3
01 - 1
Example 2:

Input: 0
Output: [0]
Explanation: We define the gray code sequence to begin with 0.
             A gray code sequence of n has size = 2n, which for n = 0 the size
is 20 = 1.              Therefore, for n = 0 the gray code sequence is [0].

*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
  /*
  一. 公式法
  从0遍历到(1 << n) -1, 即位数为n的最大值
  格林编码公式：graycode = i ^ i >> 1;

  二，动态规划，找规律
  1. 从最简单n=0的时候作为起点出发不断给ans增加元素
  2. 第m次迭代增加的元素无非是对二进制第m位的0改为1
  3. 那也就是原来的每个元素加上2^(m-1)便得到了
  4.
  唯一要注意的是每一次迭代都要把顺序倒一遍使得新增的元素的头头和原有元素的尾巴还是符合格雷相连性质的

  复杂度：
  时间复杂度：O(n)
  空间复杂度：O(1)
*/
 public:
#if 0
  vector<int> grayCode(int n) {
    vector<int> result;
    for (int i = 0; i < (1 << n); ++i) {
      result.push_back(i ^ i >> 1);
    }

    return result;
  }
#endif
  vector<int> grayCode(int n) {
    vector<int> result;
    result.push_back(0);
    for (int i = 0; i < n; ++i) {
      int add = 1 << i;
      for (int j = result.size() - 1; j >= 0; --j) {
        result.push_back(add + result[j]);
      }
    }

    return result;
  }
};

int main() {
  Solution sol;
  auto result = sol.grayCode(3);
  for (auto &e : result) {
    cout << e << " ";
  }

  cout << endl;
}
