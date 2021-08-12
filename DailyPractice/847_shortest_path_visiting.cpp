#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
 private:
  vector<vector<int>> myGraph;
  vector<int> cacheList;
  int minCount;
  int count;
 
 public:
  int shortestPathLength(vector<vector<int>>& graph) {
    count = graph.size();
    if (count == 0) {
      return 0;
    }
    // Init
    minCount = INT_MAX;
    vector<int> middleMap(count, 0);
    cacheList = middleMap;
    myGraph = graph;
    // DFS
    for (int i = 0; i < graph.size(); i++) {
      dfs(i, -1);
    }
    return minCount;
  }

  void dfs(int currentNode, int currentCount) {
    // exception
    if (isAllConnected()) {
      minCount = min(currentCount, minCount);
      return;
    }
    if (currentCount >= minCount) {
      return;
    }
    // process
    cacheList[currentNode] += 1;
    currentCount += 1;
    // next
    for (auto edge : myGraph[currentNode]) {
      if (cacheList[edge] == 0) {
        dfs(edge, currentCount);
        break;
      }
    }
    for (auto edge: myGraph[currentNode]) {
      dfs(edge, currentCount);
    }
    // clean
    cacheList[currentNode] -= 1;
    currentCount -= 1;
  }

  bool isAllConnected() {
    for (int i = 0; i < count; i++) {
      printf("%i \n", i);
      if (cacheList[i] == 0) {
        return false;
      }
    }
    return true;
  }
};

int main() {
  Solution solve;
  vector<vector<int>> graph = {{1}, {0,2,6}, {1,3}, {2},{5},{4,6}, {1,5,7}, {6}};
  int step = solve.shortestPathLength(graph);
  return 0;
}