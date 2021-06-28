#include <vector>
#include <unordered_map>
using namespace std;
struct Point {
  int x;
  int y;
};
class Solution {
private:
  int rowSize = 6;
  int columnSize = 6;
  int totalSize = 36;
  int result = -1;
 public:
  int snakesAndLadders(vector<vector<int>>& board) {
    rowSize = board.size();
    columnSize = board[0].size();
    totalSize = rowSize * columnSize;
    unordered_map<int, int> visitedCache;
    vector<int> bfsVec;
    result = - 1;
    // init
    bfsVec.push_back(1);
    visitedCache[1] = 0;
    while (!bfsVec.empty()) {
      int top = bfsVec[0];
      bfsVec.erase(bfsVec.begin());
      for (int i = 1; i <= 6; i++) {
        int nextValue = top + i;
        if (nextValue > totalSize) {
          break;
        }
        // check if on snake or ladder
        auto point = caculateBoardIndex(nextValue);
        if (board[point.x][point.y] != -1) {
          nextValue = board[point.x][point.y];
        }
        // check result
        if (nextValue == totalSize) {
          updateMin(visitedCache[top] + 1);
          visitedCache[nextValue] = visitedCache[top] + 1;
        } else {
          if (visitedCache.find(nextValue) != visitedCache.end()) {
            continue;
          } else {
            visitedCache[nextValue] = visitedCache[top] + 1;
            bfsVec.push_back(nextValue);
          }
        }
      }
    }
    return result;
  }

  Point caculateBoardIndex(int current) {
    int rowIndex = (rowSize - 1) - (current-1) / columnSize;
    int columnIndex =
        ((rowSize - 1 - rowIndex) % 2 == 0)
            ? ((current - 1) - (rowSize - 1 - rowIndex) * columnSize) 
            : (columnSize - 1) - ((current - 1) - (rowSize - 1 - rowIndex) * columnSize);
    return Point{rowIndex, columnIndex};
  }

  void updateMin(int step) {
    if (result == -1) {
      result = step;
    } else {
      result = min(result, step);
    }
  }
};

int main() {
  Solution solve;
  vector<vector<int>> test = {
      {-1, -1, -1, -1, -1, -1}, {-1, -1, -1, -1, -1, -1},
      {-1, -1, -1, -1, -1, -1}, {-1, 35, -1, -1, 13, -1},
      {-1, -1, -1, -1, -1, -1}, {-1, 15, -1, -1, -1, -1}};
  int result = solve.snakesAndLadders(test);
  return 0;
}