#include <vector>
#include <string>
#include <unordered_map>
using namespace std;
class Solution {
 public:
  int slidingPuzzle(vector<vector<int>>& board) {
    string puzzel = "";
    string target = "123450";
    for (int i = 0; i < board.size(); i++) {
      for (int j = 0; j < board[i].size(); j++) {
        puzzel += to_string(board[i][j]);
      }
    }
    if (puzzel == target) {
      return 0;
    }
    unordered_map<string, int> visited;
    vector<string> bfs;
    visited[puzzel] = 0;
    bfs.push_back(puzzel);
    int result = -1;
    while (!bfs.empty()) {
      string current = bfs[0];
      bfs.erase(bfs.begin());
      int zeroIndex = 0;
      for (int i = 0; i < current.size(); i++) {
        if (current[i] == '0') {
          zeroIndex = i;
          break;
        }
      }
      // left
      if (zeroIndex != 0 && zeroIndex != 3) {
        int leftIndex = zeroIndex - 1;
        updateBFSVec(visited, zeroIndex, leftIndex, bfs, current, result, target);
      }
      // right
      if (zeroIndex != 2 && zeroIndex != 5) {
        int rightIndex = zeroIndex + 1;
        updateBFSVec(visited, zeroIndex, rightIndex, bfs, current, result,
                     target);
      }
      // top
      if (zeroIndex > 2) {
        int topIndex = zeroIndex - 3;
        updateBFSVec(visited, zeroIndex, topIndex, bfs, current, result,
                     target);
      }
      // bottom
      if (zeroIndex <= 2) {
        int bottomIndex = zeroIndex + 3;
        updateBFSVec(visited, zeroIndex, bottomIndex, bfs, current, result,
                     target);
      }
      if (result != -1) {
        return result;
      }
    }
    return result;
  }

  void updateBFSVec(unordered_map<string, int> &visited, int zeroIndex, int changeIndex, vector<string> &bfs, string currentString, int &small, string target) {
    char temp = currentString[zeroIndex];
    int currentStep = visited[currentString];
    currentString[zeroIndex] = currentString[changeIndex];
    currentString[changeIndex] = temp;
    if (visited.find(currentString) != visited.end()) {
      // duplicate
      return;
    }
    if (currentString == target) {
      // success
      if (small == -1) {
        small = currentStep + 1;
      } else {
        small = small < (currentStep + 1) ? small : currentStep + 1;
      }
      return;
    }
    visited[currentString] = currentStep + 1;
    bfs.push_back(currentString);
  }
};

int main() {
  Solution solve;
  vector<vector<int>> board = {{4,1,2},{5,0,3}};
  int step = solve.slidingPuzzle(board);
  return 0;
}