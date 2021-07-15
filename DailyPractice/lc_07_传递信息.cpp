#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;
class Solution {
 public:
  /// BFS solutin.
  int numWays(int n, vector<vector<int>>& relation, int k) {
    unordered_map<int, unordered_set<int>> relationMap;
    for  (int i = 0; i < relation.size(); i++) {
      for (int j = 1; j < relation[i].size(); j++) {
        relationMap[relation[i][0]].insert(relation[i][j]);
      }
    }
    vector<int> dp;
    dp.push_back(0);
    while (!dp.empty() && k != 0) {
      int size = dp.size();
      // 消除每层
      while (size > 0) {
        int top = dp[0];
        dp.erase(dp.begin());
        for (auto next : relationMap[top]) {
          dp.push_back(next);
        }
        size--;
      }
      k--;
    }
    int solution = 0;
    for (auto point: dp) {
      solution = point == n - 1 ? solution + 1 : solution;
    }
    return solution;
  }
};

int main() {
  Solution slove;
  vector<vector<int>> relations = {{0,2}, {2,1}, {3,4}, {2,3}, {1,4}, {2,0}, {0,4}};
  int result = slove.numWays(5, relations, 3);
  return 0;
}