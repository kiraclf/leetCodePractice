#include <vector>
using namespace std;
class Solution {
 public:
  int trapRainWater(vector<vector<int>>& heightMap) {
    int maxHeight = 0;
    for (auto heightList : heightMap) {
      for (auto height : heightList) {
        maxHeight = max(height, maxHeight);
      }
    }
    int totalWater = 0;
    for (int i = 1; i <= maxHeight; i++) {
    }
  }

  void generateCurrentHeightMap(vector<vector<int>>& heightMap,
                                vector<vector<int>>& current, int currentHeight,
                                int& water) {
    for (int i = 0; i < current.size(); i++) {
      for (int j = 0; j < current[i].size(); j++) {
        if (current[i][j] == -1) {
          continue;
        } else if (heightMap[i][j] >= currentHeight) {
          current[i][j] = 1;
        }
      }
    }
  }
};