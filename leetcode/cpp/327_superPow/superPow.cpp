//
// Created by kayxhding on 2020-05-22 08:08:50
//

/*
   Your task is to calculate a^b mod 1337 where a is a positive integer and b is
an extremely large positive integer given in the form of an array. Example 1:

Input: a = 2, b = [3]
Output: 8
Example 2:

Input: a = 2, b = [1,0]
Output: 1024
*/

#include <initializer_list>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  /*
方法：快速幂
快速幂 + 迭代
1.
x^n，其实就是把n转化为二进制后，把为1的位数不断进行x的平方叠加，若n=（101111)，
那么 n= 2^0 + 2^1 + 2^2 + 2^3 +2^5）, x^n = x^(2^0) +  x^(2^1)  + x^(2^2) +
x^(2^3) +  x^(2^5)

2. 这里要对a^b % 1337, 为了不溢出，每次计算结果都进行取模（(a * b) % k = (a %
k)(b % k) % k） 时间复杂度：O(logn)，即为对 nn 进行二进制拆分的时间复杂度。
空间复杂度：O(1)。
*/

  int superPow(int a, vector<int>& b) {
    int result = 1;
    for (auto i = 0; i < b.size(); ++i) {
      result = quickPow(result, 10) * quickPow(a, b[i]) % kMod;
    }

    return result;
  }

  int64_t quickPow(int a, int n) {
    int64_t result = 1;
    int contribute = a;
    while (n > 0) {
      if (n & 1 == 1) {
        result *= contribute % kMod;
      }

      contribute *= contribute % kMod;
      n >>= 1;
    }

    return result;
  }

 private:
  const int kMod = 1337;
};

int main() {
  vector<int> b = {1, 0, 0, 0};
  Solution sol;
  auto result = sol.superPow(2, b);

  cout << result << endl;
}
