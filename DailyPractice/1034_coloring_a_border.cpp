#include <unordered_set>
#include <vector>
using namespace std;
class Solution {
 public:
  vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col,
                                  int color) {
    unordered_set<int> visited;
    vector<int> toChangeIndex;
    borderRecursive(toChangeIndex, visited, grid, row, col, grid[row][col]);
    for (auto index : toChangeIndex) {
      int row = index / ((int)grid[0].size());
      int col = index % ((int)grid[0].size());
      grid[row][col] = color;
    }
    return grid;
  }

  void borderRecursive(vector<int>& toChangeIndx, unordered_set<int>& visited,
                       vector<vector<int>>& grid, int row, int col,
                       int targetColor) {
    int pointIndex = row * grid[0].size() + col;
    // already visited.
    if (visited.find(pointIndex) != visited.end()) {
      return;
    }
    // not the same color
    if (grid[row][col] != targetColor) {
      visited.insert(pointIndex);
      return;
    }
    // the same color, check if is border
    if (row == 0 || row == grid.size() - 1 || col == 0 ||
        col == grid[0].size() - 1) {
      // is border
      toChangeIndx.push_back(pointIndex);
    } else {
      // not border, check top left right bottom
      int leftColor = grid[row][col - 1];
      int rightColor = grid[row][col + 1];
      int topColor = grid[row - 1][col];
      int bottomColor = grid[row + 1][col];
      if (!(leftColor == targetColor && rightColor == targetColor &&
            topColor == targetColor && bottomColor == targetColor)) {
        // border
        toChangeIndx.push_back(pointIndex);
      }
    }
    // save visited
    visited.insert(pointIndex);
    // move left, right
    if (col - 1 >= 0) {
      borderRecursive(toChangeIndx, visited, grid, row, col - 1, targetColor);
    }
    if (col + 1 < grid[0].size()) {
      borderRecursive(toChangeIndx, visited, grid, row, col + 1, targetColor);
    }
    // move top, bottom
    if (row - 1 >= 0) {
      borderRecursive(toChangeIndx, visited, grid, row - 1, col, targetColor);
    }
    if (row + 1 < grid.size()) {
      borderRecursive(toChangeIndx, visited, grid, row + 1, col, targetColor);
    }
  }
};

int main() {
  Solution solution;
  vector<vector<int>> vec = {{1, 1, 1}, {1, 1, 1}, {1, 1, 1}};
  vector<vector<int>> res = solution.colorBorder(vec, 0, 1, 2);
  return 0;
}