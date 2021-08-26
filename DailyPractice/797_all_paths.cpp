#include <vector>
using namespace std;
class Solution {
 public:
  vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
    vector<long long> bfs;
    vector<vector<int>> ans;
    bfs.push_back(0);
    while (!bfs.empty()) {
      long long end = bfs[bfs.size() - 1];
      bfs.pop_back();
      int index = end & 15;
      for (auto edge : graph[index]) {
        long long next = (end << 4) + edge;
        if (edge == graph.size() - 1) {
          // ans
          ans.push_back(createRoute(next));
        }
        bfs.push_back(next);
      }
    }
    return ans;
  }

  vector<int> createRoute(long long number) {
    vector<int> path;
    while (number != 0) {
      int currentIndex = number & 15;
      path.push_back(currentIndex);
      number = number >> 4;
    }
    path.push_back(0);
    reverse(path.begin(), path.end());
    return path;
  }
};

int main() {
  Solution solve;
  vector<vector<int>> graph = {{4,3,1}, {3,2,4}, {3}, {4}, {}};
  vector<vector<int>> ans = solve.allPathsSourceTarget(graph);
  return 0;
}