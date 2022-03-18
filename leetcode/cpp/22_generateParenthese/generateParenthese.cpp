//
// Created by kayxhding on 2020-04-23 23:35:12
//

/*
Given n pairs of parentheses, write a function to generate all combinations of
well-formed parentheses.

For example, given n = 3, a solution set is:

[
  "((()))",
  "(()())",
  "(())()",
  "()(())",
  "()()()"
]
*/

#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;

class Solution {
    /*
    DFS. 对这种列出所有结果的题目，都可以考虑用递归来解
    1. 字符串只有左括号和右括号两种，每种3个
    2. 令left =0， right = 0， 若某次递归出现right > left || left > n || right >
    n时，直接返回 3， 若left == n && right == n时，说明左右 括号都打印完了，
    否则left+1进行打印左括号递归，再right+1，进行打印右括号递归
  */
   public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        dfs(result, 0, 0, n, "");
        return result;
    }

    void dfs(vector<string> &result, int left, int right, int n, string out) {
        // left < right,  invalid
        if (left > n || right > n) {
            return;
        }

        if (left == n && right == n) {
            result.push_back(out);
        }

        dfs(result, left + 1, right, n, out + '(');

        // left <= right,  不能加")", 此时只能加"("
        if (left > right) {
            dfs(result, left, right + 1, n, out + ')');
        }
    }
};

int main() {
    Solution sol;
    auto result = sol.generateParenthesis(3);
    for (auto i = 0; i < result.size(); ++i) {
        cout << result[i] << " ";
    }
    cout << endl;
}
