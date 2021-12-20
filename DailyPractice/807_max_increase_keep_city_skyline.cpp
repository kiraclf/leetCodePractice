#include <vector>
using namespace std;
class Solution {
 public:
  int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
    // 水平方向的天际线
    vector<int> horiMax(grid.size(), 0);
    // 竖直方向的天际线
    vector<int> vertMax(grid[0].size(), 0);
    // process
    for (int i = 0; i < grid.size(); i++) {
      int highest = 0;
      for (int j = 0; j < grid[i].size(); j++) {
        highest = max(highest, grid[i][j]);
      }
      horiMax[i] = highest;
    }
    for (int j = 0; j < grid[0].size(); j++) {
      int highest = 0;
      for (int i = 0; i < grid.size(); i++) {
        highest = max(highest, grid[i][j]);
      }
      vertMax[j] = highest;
    }
    // to max
    int total = 0;
    for (int i = 0; i < grid.size(); i++) {
      for (int j = 0; j < grid[0].size(); j++) {
        int highest = min(horiMax[i], vertMax[j]);
        total += highest - grid[i][j];
      }
    }
    return total;
  }
};

int main() {
  Solution solve;
  vector<vector<int>> test = {
      {3, 0, 8, 4}, {2, 4, 5, 7}, {9, 2, 6, 3}, {0, 3, 1, 0}};
  int total = solve.maxIncreaseKeepingSkyline(test);
  return 0;
}