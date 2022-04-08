#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
 public:
  vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
    if (n == 1) {
      return {0};
    }
    // init degress and childs
    unordered_map<int, int> degress;
    unordered_map<int, vector<int>> childs;
    for (int i = 0; i < edges.size(); i++) {
      int firstNode = edges[i][0];
      int secondNode = edges[i][1];
      childs[firstNode].push_back(secondNode);
      childs[secondNode].push_back(firstNode);
    }
    for (auto child : childs) {
      degress[child.first] = child.second.size();
    }
    // find all degree = 1 's edge
    queue<int> cache;
    for (auto degree : degress) {
      if (degree.second == 1) {
        cache.push(degree.first);
      }
    }
    // bfs
    vector<int> res;
    while (!cache.empty()) {
      res.clear();
      // poll all the node;
      int currentSize = cache.size();
      for (int i = 0; i < currentSize; i++) {
        int node = cache.front();
        cache.pop();
        degress[node]--;
        res.push_back(node);
        for (auto child : childs[node]) {
          degress[child]--;
          if (degress[child] == 1) {
            cache.push(child);
          }
        }
      }
    }
    return res;
  }
};