#include <vector>
#include <unordered_set>
using namespace std;
class Solution {
 public:
  bool isValidSudoku(vector<vector<char>>& board) {
    for (int i = 0; i < board.size(); i++) {
      if (!checkSingleRow(board[i])) {
        return false;
      }
    }
    for (int i = 0; i < board[0].size(); i++) {
      if (!checkSingleColumn(i, board)) {
        return false;
      }
    }
    for (int column = 0; column < board.size(); column += 3) {
      for (int row = 0; row < board[column].size(); row += 3) {
        if (!singleArea(column, row, board)) {
          return false;
        }
      }
    }
    return true;
  }

  bool checkSingleRow(vector<char>& row) {
    unordered_set<int> test;
    for (auto digit : row) {
      if (digit == '.') {
        continue;
      } else {
        int number = digit - '0';
        if (test.find(number) != test.end()) {
          return false;
        }
        test.insert(number);
      }
    }
    return true;
  }

  bool checkSingleColumn(int index, vector<vector<char>>& column) {
    unordered_set<int> test;
    for (int i = 0; i < column.size(); i++) {
      char digit = column[i][index];
      if (digit == '.') {
        continue;
      } else {
        int number = digit - '0';
        if (test.find(number) != test.end()) {
          return false;
        }
        test.insert(number);
      }
    }
    return true;
  }

  bool singleArea(int column, int row, vector<vector<char>>& board) {
    unordered_set<int> test;
    for (int i = column; i < column + 3; i++) {
      for (int j = row; j < row + 3; j++) {
        char digit = board[i][j];
        if (digit == '.') {
          continue;
        } else {
          int number = digit - '0';
          if (test.find(number) != test.end()) {
            return false;
          }
          test.insert(number);
        }
      }
    }
    return true;
  }
};