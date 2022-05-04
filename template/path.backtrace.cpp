
/*
 给定一个 m x n 二维字符网格 board 和一个字符串单词 word 。如果 word
存在于网格中，返回 true ；否则，返回 false 。

单词必须按照字母顺序，通过相邻的单元格内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。同一个单元格内的字母不允许被重复使用。

例如，在下面的 3×4 的矩阵中包含单词 "ABCCED"（单词中的字母已标出）。

示例 1：

输入：board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word =
"ABCCED" 输出：true 示例 2：

输入：board = [["a","b"],["c","d"]], word = "abcd"
输出：false
 

提示：

1 <= board.length <= 200
1 <= board[i].length <= 200
board 和 word 仅由大小写英文字母组成

*/

/*
 * 路径问题模板
 *
 */

#include <iostream>
#include <string>
#include <utility>
#include <vector>
using namespace std;

class Solution {
   public:
    bool exist(vector<vector<char>> &board, string word) {
        vector<vector<int>> visited(board.size(), vector<int>(board[0].size()));
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[i].size(); ++j) {
                bool has = backtrace(board, i, j, visited, word, 0);
                if (has) {
                    return true;
                }
            }
        }

        return false;
    }

    bool backtrace(vector<vector<char>> &input, int i, int j,
                   vector<vector<int>> &visited, string &word, int k) {
        if (input[i][j] != word[k]) {
            return false;
        }

        if (k == word.length() - 1) {
            return true;
        }

        visited[i][j] = true;
        vector<pair<int, int>> directions = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};

        bool result = false;
        // 检测4个方向
        for (auto &dir : directions) {
            int ni = i + dir.first;
            int nj = j + dir.second;
            if (ni >= 0 && ni < input.size() && nj >= 0 &&
                nj < input[0].size()) {
                // 没有访问过
                if (!visited[ni][nj]) {
                    bool has = backtrace(input, ni, nj, visited, word, k + 1);
                    if (has) {
                        result = true;
                        break;
                    }
                }
            }
        }
        visited[i][j] = false;
        return result;
    }
};

int main() {
    Solution sol;
    vector<vector<char>> board = {
        {'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'}};
    string word = "ABCCED";
    auto result = sol.exist(board, word);
    std::cout << result << std::endl;
}
