#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;
class Solution {
 public:
  vector<int> loudAndRich(vector<vector<int>> &richer, vector<int> &quiet) {
    int n = quiet.size();
    // 建立图, [i, j] 表示存在 j > i 的一条边
    vector<vector<int>> g(n);
    for (auto &r : richer) {
      g[r[1]].emplace_back(r[0]);
    }
    // 记忆化 DFS 搜索
    vector<int> ans(n, -1);
    function<void(int)> dfs = [&](int x) {
      if (ans[x] != -1) {
        return;
      }
      ans[x] = x;
      for (int y : g[x]) {
        dfs(y);
        if (quiet[ans[y]] < quiet[ans[x]]) {
          ans[x] = ans[y];
        }
      }
    };
    for (int i = 0; i < n; ++i) {
      dfs(i);
    }
    return ans;
  }
};

int main() {
  Solution solve;
  vector<vector<int>> richer = {{1, 0}, {2, 1}, {3, 1}, {3, 7},
                                {4, 3}, {5, 3}, {6, 3}};
  vector<int> quiet = {3, 2, 5, 4, 6, 1, 7, 0};
  vector<int> res = solve.loudAndRich(richer, quiet);
  return 0;
}