//
// Created by kayxhding on 2020-09-01 07:19:42
//

/*
   Given a 2D board containing 'X' and 'O' (the letter O), capture all regions
surrounded by 'X'.

A region is captured by flipping all 'O's into 'X's in that surrounded region.

Example:

X X X X
X O O X
X X O X
X O X X
After running your function, the board should be:

X X X X
X X X X
X X X X
X O X X
Explanation:

Surrounded regions shouldn’t be on the border, which means that any 'O' on the
border of the board are not flipped to 'X'. Any 'O' that is not on the border
and it is not connected to an 'O' on the border will be flipped to 'X'. Two
cells are connected if they are adjacent cells connected horizontally or
vertically.

*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  /*
方法一： dfs
1.
矩形的边界的O都是不需要改写为X的，从边界的每个点出发，深度优选搜索，若果不是O的就改为A作为标记，表示访问过了，否是是O就不改其值
2.
然后深度搜索其相邻的4个点，直到坐标点无效或者该点坐标为O后退出，递归依次返回（即该从起点出发后达到点终点后依次返回，递归结束）
3. 之后遍历被标记过后的board，如果board[i][j] == 'A',
那么就代表改点是不被X包围点，需要改写为O
4. 否则如果board[i][j] ==
'O',即没有被访问过，那么就代表该点是被X包围点，需要改写为X

时间复杂度：O(m*n)
空间复杂度：O(m*n),深度优选栈点开销
*/
  void solve(vector<vector<char>>& board) {
    int rows = board.size();
    if (rows == 0) {
      return;
    }
    int cols = board[0].size();

    for (int i = 0; i < rows; ++i) {
      dfs(board, i, 0);
      dfs(board, i, cols - 1);
    }
    for (int i = 0; i < cols; ++i) {
      dfs(board, 0, i);
      dfs(board, rows - 1, i);
    }

    for (auto i = 0; i < rows; ++i) {
      for (auto j = 0; j < cols; ++j) {
        if (board[i][j] == 'A') {
          board[i][j] = 'O';
        } else if (board[i][j] == 'O') {
          board[i][j] = 'X';
        }
      }
    }
  }

  void dfs(vector<vector<char>>& board, int x, int y) {
    int rows = board.size();
    if (rows == 0) {
      return;
    }
    int cols = board[0].size();

    if (x < 0 || x >= rows || y < 0 || y >= cols || board[x][y] != 'O') {
      return;
    }
    board[x][y] = 'A';
    dfs(board, x - 1, y);
    dfs(board, x + 1, y);
    dfs(board, x, y - 1);
    dfs(board, x, y + 1);
  }
};

int main() {
  vector<vector<char>> board = {{'X', 'X', 'X', 'X'},
                                {'X', 'O', 'O', 'X'},
                                {'X', 'X', 'O', 'X'},
                                {'X', 'O', 'X', 'X'}};
  Solution sol;
  sol.solve(board);
  for (auto& rows : board) {
    for (auto& e : rows) {
      std::cout << e << " ";
    }
    std::cout << std::endl;
  }
}
