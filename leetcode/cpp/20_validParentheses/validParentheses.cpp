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
        //注意这里括号映射，key为右括号，value为左括号，因为先有左括号，
        //因此可以将右括号放入stack中
        map<char, char> parenthesePair = {
            {')', '('},
            {']', '['},
            {'}', '{'},
        };

        for (auto i = 0; i < s.length(); ++i) {
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
