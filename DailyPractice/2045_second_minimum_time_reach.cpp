#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;
class Solution {
 public:
  int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
    // key: node, value: list of connected nodes
    unordered_map<int, unordered_set<int>> edgesMap;
    // different level visited count
    unordered_map<int, int> visitedCount;
    unordered_set<int> nextNode;
    for (auto edge : edges) {
      edgesMap[edge[0]].insert(edge[1]);
      edgesMap[edge[1]].insert(edge[0]);
    }
    queue<int> cache;
    cache.push(1);
    visitedCount[1] = 1;
    int currentTime = 0;
    int firstTouchTime = -1;
    while (cache.size() != 0) {
      if (isGreen(currentTime, change)) {
        // make jump
        int size = cache.size();
        currentTime += time;
        nextNode.clear();
        while (size > 0) {
          int top = cache.front();
          cache.pop();
          for (auto edge : edgesMap[top]) {
            if (nextNode.find(edge) != nextNode.end()) {
              continue;
            } else {
              nextNode.insert(edge);
            }
            if (edge == n) {
              if (firstTouchTime == -1) {
                firstTouchTime = currentTime;
              } else if (firstTouchTime != currentTime) {
                return currentTime;
              }
            }
          }
          size--;
        }
        for (auto next : nextNode) {
          visitedCount[next] += 1;
          if (visitedCount[next] <= 2) {
            cache.push(next);
          }
        }
      } else {
        currentTime++;
      }
    }
    return -1;
  }

  bool isGreen(int time, int change) { return (time % (change * 2)) < change; }
};

int main() {
  Solution solve;
  int n = 5;
  vector<vector<int>> edges = {{1, 2}, {1, 3}, {1, 4}, {3, 4}, {4, 5}};
  int time = 3;
  int change = 5;
  int scond = solve.secondMinimum(n, edges, time, change);
  return 0;
}