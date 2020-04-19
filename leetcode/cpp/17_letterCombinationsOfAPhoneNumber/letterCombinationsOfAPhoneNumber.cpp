//
// Created by kayxhding on 2020-04-19 19:18:43
//

/*
   Given a string containing digits from 2-9 inclusive, return all possible
letter combinations that the number could represent.

A mapping of digit to letters (just like on the telephone buttons) is given
below. Note that 1 does not map to any letters. Example:

Input: "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
Note:

Although the above answer is in lexicographical order, your answer could be in
any order you want.
*/

#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

class Solution {
 public:
  /*
  思路：
  回溯是一种通过穷举所有可能情况来找到所有解的算法。如果一个候选解最后被发现并不是可行解，回溯算法会舍弃它，并在前面的一些步骤做出一些修改，并重新尝试找到可行解

  1. 简历映射表（char->string）
  2. 获取当前数字所对应的字符串
  3. 获取当前字符串的一个字符
  4. 将一个目前已经产生的组合 combination 和接下来准备要输入的数字 digits
  作为参数， 如果没有更多的数字需要被输入，那意味着当前的组合已经产生好了。
    如果还有数字需要被输入，遍历下一个数字所对应的所有映射的字母

  复杂度：
  1. 时间复杂度： O(3^N * 4^M)，其中 N 是输入数字中对应 3 个字母的数目（比方说
  2，3，4，5，6，8）， M 是输入数字中对应 4 个字母的数目（比方说 7，9），N+M
  是输入数字的总数
  2. 空间复杂度：O(3^N * 4^M)， 这是因为需要保存 3^N * 4^M3 个结果
*/
  vector<string> letterCombinations(string digits) {
    std::map<char, string> digits_letters_map = {
        {'2', "abc"}, {'3', "def"},  {'4', "ghi"}, {'5', "jkl"},
        {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}};

    std::string combination;
    vector<string> result;
    backtrace(combination, digits, digits_letters_map, result);

    return result;
  }

  void backtrace(const std::string &combination, const std::string &digits,
                 map<char, string> &digits_letters_map,
                 std::vector<string> &result) {
    if (digits.length() == 0) {
      result.push_back(combination);
      return;
    }

    std::string letters = digits_letters_map[digits[0]];
    for (auto i = 0; i < letters.length(); ++i) {
      std::string letter = letters.substr(i, 1);
      backtrace(combination + letter, digits.substr(1), digits_letters_map,
                result);
    }
  }
};

int main() {
  std::string digits = "23";
  Solution sol;
  auto result = sol.letterCombinations(digits);
  for (auto i = 0; i < result.size(); ++i) {
    cout << result[i] << " ";
  }
  cout << endl;
}
