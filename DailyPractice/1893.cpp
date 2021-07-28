#include <vector>
using namespace std;
class Solution {
 public:
  bool isCovered(vector<vector<int>>& ranges, int left, int right) {
    vector<int> cache(50, 0);
    for (auto range : ranges) {
      int left = range[0];
      int right = range[1];
      for (int i = left - 1; i < right; i++) {
        cache[i] = 1;
      }
    }
    for (int i = left - 1; i < right; i++) {
      if (cache[i] == 0) {
        return false;
      }
    }
    return true;
  }
};
