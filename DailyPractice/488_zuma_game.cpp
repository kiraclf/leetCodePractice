#include <string>
#include <unordered_map>
using namespace std;

class Solution {
 public:
  int findMinStep(string board, string hand) {
    int minCount = -1;
    unordered_map<char, int> handMap;
    for (auto character : hand) {
      handMap[character] += 1;
    }
    dfs(board, handMap, &minCount);
    return minCount;
  }

  void dfs(string board, unordered_map<char, int> hand, int &minCount) {}

  bool update(string &board) {
    bool update = false;
    int start = 0;
    while (start < board.size() - 2) {
      char current = board[start];
      int len = 1;
      while (start + len < board.size() && current == board[start + len]) {
        len++;
      }
      if (len >= 3) {
        update = true;
        // clear
        string before = board.substr(0, start);
        string after;
        if (board.size() - before.size() - len > 0) {
          after = board.substr(start + len, board.size() - before.size() - len);
        } else {
          after = "";
        }
        board = before + after;
        start -= 2;
      } else {
        start++;
      }
    }
    return update;
  }
};