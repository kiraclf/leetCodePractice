#include <string>
#include <vector>
using namespace std;
class Solution {
 public:
  bool validTicTacToe(vector<string>& board) {
    if (board[0] == "   " && board[0] == board[1] && board[1] == board[2]) {
      return true;
    }
    for (int i = 0; i < board.size(); i++) {
      for (int j = 0; j < board[i].size(); j++) {
        if (board[i][j] != ' ') {
          char temp = board[i][j];
          board[i][j] = ' ';
          bool res = validBefore(board, temp);
          board[i][j] = temp;
          if (res) {
            return res;
          }
        }
      }
    }
    return false;
  }

  bool validBefore(vector<string>& board, char lastCharacter) {
    int firstCount = 0;
    int secondCount = 0;
    bool threeTheSame = false;
    // check diagonal
    if (board[0][0] != ' ' && board[0][0] == board[1][1] &&
        board[1][1] == board[2][2]) {
      return false;
    }
    if (board[0][2] != ' ' && board[0][2] == board[1][1] &&
        board[1][1] == board[2][0]) {
      return false;
    }
    for (int i = 0; i < 3; i++) {
      if (board[0][i] != ' ' && board[0][i] == board[1][i] &&
          board[1][i] == board[2][i]) {
        return false;
      }
    }
    // check line
    for (auto row : board) {
      if (row == "XXX" || row == "OOO") {
        threeTheSame = true;
        break;
      }
      for (auto character : row) {
        if (character == 'O') {
          secondCount += 1;
        } else if (character == 'X') {
          firstCount += 1;
        }
      }
    }
    if (firstCount - secondCount > 1 || secondCount > firstCount ||
        firstCount + secondCount == 9 || threeTheSame) {
      return false;
    }
    if (firstCount == secondCount && lastCharacter != 'X') {
      return false;
    }
    if (firstCount > secondCount && lastCharacter != 'O') {
      return false;
    }
    return true;
  }
};