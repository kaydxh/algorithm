//
// Created by kayxhding on 2020-04-14 10:14:24
//

/*
Given a string, find the length of the longest substring without repeating
characters.

Example 1:

Input: "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.
Example 2:

Input: "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
Example 3:

Input: "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
             Note that the answer must be a substring, "pwke" is a subsequence
and not a substring.

*/

#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
 public:
  /*
  滑动窗口法：
  说明：
  a. 用unordered_map保存每个字符与其对应的索引位置
  b. lastRepeatedPos保存最近一次重复字符的位置

  1.
  在遍历字符串s过程中，先从unordered_map里查找是否有该字符，如果有，且该重复字符的索引>lastRepeatedPos就更新lastRepeatedPos，否则不做任何更新
  2.接着判断 i-lastRepeatedPos > maxlen是否成立，若成立，就更新maxLen
  3. unordered_map里更新字符和index
  复杂度：
  1. 时间复杂度：O(n)
  2. 空间复杂度：O(n)
*/

  int lengthOfLongestSubstring(string s) {
    int maxLen = 0;
    int lastRepeatedPos = -1;
    unordered_map<char, int> value_index_map;
    for (auto i = 0; i < s.length(); ++i) {
      auto iter = value_index_map.find(s[i]);
      if (iter != value_index_map.end() && lastRepeatedPos < iter->second) {
        lastRepeatedPos = iter->second;
      }

      if (i - lastRepeatedPos > maxLen) {
        maxLen = i - lastRepeatedPos;
      }

      value_index_map[s[i]] = i;
    }

    return maxLen;
  }
};

int main() {
  string s = "abcabcbb";
  Solution sol;
  auto maxLen = sol.lengthOfLongestSubstring(s);
  cout << maxLen << endl;
  return 0;
}
