/*
 Write a function to find the longest common prefix string amongst an array of
strings.

If there is no common prefix, return an empty string "".


Example 1:

Input: strs = ["flower","flow","flight"]
Output: "fl"
Example 2:

Input: strs = ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.
 

Constraints:

1 <= strs.length <= 200
0 <= strs[i].length <= 200
strs[i] consists of only lower-case English letters.

*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
   public:
    /*
   1. 首选找到所有字符串的最短长度，minlen
   2. 循环遍历，最外层是从index 0 遍历到 minLen，
   内部循环是遍历不同字符串，相同位置的值是否相等

   复杂度：
   1. 时间复杂度：O(S)
   2. 空间复杂度：O(1)
   */
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) {
            return "";
        }
        int minLen = strs[0].length();
        for (int i = 1; i < strs.size(); i++) {
            if (strs[i].length() < minLen) {
                minLen = strs[i].length();
            }
        }

        for (auto i = 0; i < minLen; ++i) {
            for (auto j = 0; j < strs.size() - 1; ++j) {
                if (strs[j][i] != strs[j + 1][i]) {
                    return strs[0].substr(0, i);
                }
            }
        }

        return strs[0].substr(0, minLen);
    }
};

int main() {
    vector<string> strs = {"flower", "flow", "flight"};
    Solution sol;
    auto result = sol.longestCommonPrefix(strs);
    std::cout << result << std::endl;
}
