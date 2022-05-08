/*
Given a string s containing just the characters '(', ')', '{', '}', '[' and ']',
determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
 

Example 1:

Input: s = "()"
Output: true
Example 2:

Input: s = "()[]{}"
Output: true
Example 3:

Input: s = "(]"
Output: false
 

Constraints:

1 <= s.length <= 104
s consists of parentheses only '()[]{}'.
*/

#include <iostream>
#include <map>
#include <stack>
#include <string>
using namespace std;

class Solution {
   public:
    bool isValid(string s) {
        stack<char> stacks;
        // 1. 遍历字符串，遇到左括号，放入栈中
        // 2. 遇到右括号，检查该右括号和栈顶元素是否匹配，不匹配直接返回false
        // 3. 最后遍历完整，检查stack是否空了，如果是，就是完全匹配了
        // 时间复杂度：O(n)
        // 空间复杂度：O(n)
        //注意这里括号映射，key为右括号，value为左括号，因为先有左括号，
        //因此可以将右括号放入stack中
        map<char, char> parenthesePair = {
            {')', '('},
            {']', '['},
            {'}', '{'},
        };

        for (auto i = 0; i < s.length(); ++i) {
            // 将左括号放入stack中
            auto it = parenthesePair.find(s[i]);
            if (it == parenthesePair.end()) {
                stacks.push(s[i]);
            } else {
                if (!stacks.empty() && stacks.top() == parenthesePair[s[i]]) {
                    stacks.pop();
                } else {
                    return false;
                }
            }
        }

        return stacks.empty();
    }
};

int main() {
    string s = "()[]{}";
    Solution sol;
    cout << sol.isValid(s) << endl;
}
