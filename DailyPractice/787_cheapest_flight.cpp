#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;
class Solution {
 public:
  int INF = 10000 * 101 + 1;
  int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst,
                        int k) {
    // 创建 dp 数组 表示 f[经过的边数][到达的顶点] 的最小值
    vector<vector<int>> f(k + 2, vector<int>(n, INF));
    f[0][src] = 0;
    for (int i = 1; i <= k + 1; i++) {
      // 遍历边,更新当前的最短距离
      for (auto filght : flights) {
        int flightSrc = filght[0], flightDst = filght[1], cost = filght[2];
        int value = min(f[i][flightDst], f[i - 1][flightSrc] + cost);
        f[i][flightDst] = value;
      }
    }
    int ans = INF;
    for (int i = 1; i <= k + 1; i++) {
      ans = min(ans, f[i][dst]);
    }
    return (ans == INF ? -1 : ans);
  }
};

int main() {
  Solution solve;
  vector<vector<int>> edges = {{0, 1, 100}, {1, 2, 100}, {0, 2, 500}};
  int cost = solve.findCheapestPrice(3, edges, 0, 2, 0);
  return 0;
}