//
// Created by kayxhding on 2020-05-13 08:24:18
//
/*
Given two non-negative integers num1 and num2 represented as strings, return the
product of num1 and num2, also represented as a string.

Example 1:

Input: num1 = "2", num2 = "3"
Output: "6"
Example 2:

Input: num1 = "123", num2 = "456"
Output: "56088"
Note:

The length of both num1 and num2 is < 110.
Both num1 and num2 contain only digits 0-9.
Both num1 and num2 do not contain any leading zero, except the number 0 itself.
You must not use any built-in BigInteger library or convert the inputs to
integer directly.
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
 public:
  /*
遍历 num2 每一位与 num1 进行相乘，将每一步的结果进行累加。
乘数 num1 位数为 M，被乘数 num2 位数为 N， num1 x num2 结果 res 最大总位数为 M+N
num1[i] x num2[j] 的结果为 tmp(位数为两位，"0x","xy"的形式)，其第一位位于
res[i+j]，第二位位于 res[i+j+1]。

复杂度：
时间复杂度：O(m*n)
空间复杂度：O(m+n)
*/

  string multiply(string num1, string num2) {
    string result;
    int len1 = num1.length();
    int len2 = num2.length();
    vector<int> res_array(len1 + len2, 0);

    for (auto i = len1 - 1; i >= 0; --i) {
      for (auto j = len2 - 1; j >= 0; --j) {
        int n1 = num1[i] - '0';
        int n2 = num2[j] - '0';
        int mul = n1 * n2;
        int p1 = i + j;
        int p2 = i + j + 1;
        int sum = mul + res_array[p2];
        //将乘积叠加到 res_array 的正确位置
        // num1[i] 和 num2[j] 的乘积对应的就是 res_array[i+j] 和
        // res_array[i+j+1] 这两个位置

        //更新res_array的余数，这里余数不需要 +=， 因为sum已经是更新过的了
        res_array[p2] = sum % 10;
        //更新商，    res_array[p1]可以大于10，i+j 是最终结果的高位，i+j+1
        //是低位。由于计算顺序就是从右往左、从低到高的，所以每一轮都不需要高位是否要进位，下一轮自然会去处理。
        res_array[p1] += sum / 10;
      }
    }

    int i = 0;
    while (i < res_array.size() && res_array[i] == 0) {
      ++i;
    }

    for (; i < res_array.size(); ++i) {
      result += (res_array[i] + '0');
      // result.push_back(res_array[i] + '0');
    }

    return result.empty() ? "0" : result;
  }
};

int main() {
  Solution sol;
  auto result = sol.multiply("12", "7");
  cout << result << endl;
}
