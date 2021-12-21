#include <vector>
using namespace std;
class Solution {
 public:
  int countBattleships(vector<vector<char>>& board) {
    // for every x point, check it's left top
    int totalCount = 0;
    for (int i = 0; i < board.size(); i++) {
      for (int j = 0; j < board[i].size(); j++) {
        if (board[i][j] == '.') {
          continue;
        }
        // left has X
        if (j > 0 && board[i][j - 1] == 'X') {
          continue;
        }
        // top has X
        if (i > 0 && board[i - 1][j] == 'X') {
          continue;
        }
        totalCount += 1;
      }
    }
    return totalCount;
  }
};