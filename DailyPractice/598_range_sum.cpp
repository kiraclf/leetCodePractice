#include <vector>
using namespace std;
class Solution {
 public:
  int maxCount(int m, int n, vector<vector<int>>& ops) {
    int minX = INT_MAX;
    int minY = INT_MAX;
    for (auto list : ops) {
      minX = min(minX, list[0]);
      minY = min(minY, list[1]);
    }
    return minX * minY;
  }
};