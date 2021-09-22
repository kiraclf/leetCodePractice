#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
 public:
  int numberOfBoomerangs(vector<vector<int>>& points) {
    const int n = points.size();
    int ans = 0;
    unordered_map<int, int> dicts;
    for (int i = 0; i < n; ++i) {
      dicts.clear();
      for (int j = 0; j < n; ++j) {
        if (i == j) continue;
        int x1 = points[i][0], y1 = points[i][1];
        int x2 = points[j][0], y2 = points[j][1];
        long long d = (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1);
        dicts[d]++;
      }
      for (auto & [k, v] : dicts) {  // 遍历哈希表的方式
        ans += (v) * (v - 1);
      }
    }
    return ans;
  }
};