
#include <iostream>
#include <stack>
#include <string>
using namespace std;

class Solution {
   public:
    /*
     * 时间复杂度：O(N)，其中 N 是字符串 S 的长度。
     * 空间复杂度：O(N)，为栈的大小。
     */
    int scoreOfParentheses(string s) {
        stack<int> scoreStack;
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == '(') {
                //左括号，不计分，用0表示
                scoreStack.push(0);
            } else {
                int top = scoreStack.top();
                //满足 （）形式
                if (top == 0) {
                    scoreStack.pop();
                    scoreStack.push(1);
                } else {
                    // )) 形式 -> 满足(A + B + C + ...)形式
                    int t = 0;
                    while (!scoreStack.empty() && scoreStack.top() != 0) {
                        t += scoreStack.top();
                        scoreStack.pop();
                    }

                    // 去掉 (A+B+C+...), 这里的最左侧括号
                    scoreStack.pop();
                    scoreStack.push(2 * t);
                }
            }
        }

        int score = 0;
        // 最后栈内都是分数，已经没有0这种左括号了，把所有分数加起来即可
        while (!scoreStack.empty()) {
            score += scoreStack.top();
            scoreStack.pop();
        }

        return score;
    }
};

int main() {
    Solution sol;
    string s = "(()(()))";
    auto result = sol.scoreOfParentheses(s);
    std::cout << result << std::endl;
}
