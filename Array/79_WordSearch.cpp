/**
 * Given a 2D board and a word, find if the word exists in the grid.
 * The word can be constructed from letters of sequentially adjacent cell,
 * where "adjacent" cells are those horizontally or vertically neighboring.
 * The same letter cell may not be used more than once.
 */

#include <iostream>
#include <vector>

using namespace std;

/**
 * 思路 1 : ---- DFS
 * DFS --- 很难判断怎么才算重复 DFS + 回溯
 */

class Solution {
 public:
  bool exist(vector<vector<char>>& board, string word) {
    for (int i = 0; i < board.size(); i++) {
      for (int j = 0; j < board[0].size(); j++) {
        if (board[i][j] == word[0]) {
          bool has = dfsSearch({board[i][j]}, i, j, word, board.size() - 1,
                               board[0].size() - 1, 0, board);
          if (has) {
            return true;
          }
        }
      }
    }
    return false;
  }

  bool dfsSearch(string current, int x, int y, string word, int maxX, int maxY,
                 int start, vector<vector<char>>& board) {
    // 终止条件
    cout << current << endl;
    if (x < 0 || y < 0 || x > maxX || y > maxY ||
        current.size() == word.size()) {
      return current == word;
    }
    char currentC;
    if ((currentC = board[x][y]) != word[start]) return false;
    board[x][y] = '*';
    // 上
    bool top = false;
    if (y - 1 >= 0) {
      current += board[x][y - 1];
      top = dfsSearch(current, x, y - 1, word, maxX, maxY, start + 1, board);
      current.pop_back();
    }
    // 下
    bool down = false;
    if (y + 1 <= maxY) {
      current += board[x][y + 1];
      down = dfsSearch(current, x, y + 1, word, maxX, maxY, start + 1, board);
      current.pop_back();
    }
    // 左
    bool left = false;
    if (x - 1 >= 0) {
      current += board[x - 1][y];
      left = dfsSearch(current, x - 1, y, word, maxX, maxY, start + 1, board);
      current.pop_back();
    }
    // 右
    bool right = false;
    if (x + 1 <= maxX) {
      current += board[x + 1][y];
      right = dfsSearch(current, x + 1, y, word, maxX, maxY, start + 1, board);
      current.pop_back();
    }
    board[x][y] = currentC;
    return top || down || left || right;
  }
};

class OfficialSoltion {
 public:
  bool exist(vector<vector<char>>& board, string word) {
    m = board.size();
    n = board[0].size();
    for (int x = 0; x < m; x++)
      for (int y = 0; y < n; y++) {
        if (isFound(board, word.c_str(), x, y)) return true;
      }
    return false;
  }

 private:
  int m;
  int n;
  bool isFound(vector<vector<char>>& board, const char* w, int x, int y) {
    if (x < 0 || y < 0 || x >= m || y >= n || board[x][y] == '\0' ||
        *w != board[x][y])
      return false;
    if (*(w + 1) == '\0') return true;
    char t = board[x][y];
    board[x][y] = '\0';
    if (isFound(board, w + 1, x - 1, y) || isFound(board, w + 1, x + 1, y) ||
        isFound(board, w + 1, x, y - 1) || isFound(board, w + 1, x, y + 1))
      return true;
    board[x][y] = t;
    return false;
  }
};

int main() {
  Solution solve;
  vector<vector<char>> test = {
      {'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'}};
  bool has = solve.exist(test, "SEE");
  return 0;
}