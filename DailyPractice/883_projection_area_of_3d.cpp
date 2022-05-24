#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
 public:
  int projectionArea(vector<vector<int>>& grid) {
    unordered_map<int, int> xMap;
    unordered_map<int, int> yMap;
    int zArea = 0;
    for (int x = 0; x < grid.size(); x++) {
      for (int y = 0; y < grid[x].size(); y++) {
        if (grid[x][y] != 0) {
          zArea++;
        }
        xMap[x] = max(xMap[x], grid[x][y]);
        yMap[y] = max(yMap[y], grid[x][y]);
      }
    }
    int res = 0;
    for (auto value : xMap) {
      res += value.second;
    }
    for (auto value : yMap) {
      res += value.second;
    }
    return res + zArea;
  }
};

int main() {
  Solution solve;
  vector<vector<int>> test = {{2, 3}, {2, 4}};
  int res = solve.projectionArea(test);
  return 0;
}