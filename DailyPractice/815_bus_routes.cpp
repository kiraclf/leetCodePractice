#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;
class Solution {
 private:
  int minCount;

 public:
  int numBusesToDestination(
    vector<vector<int>>& routes, 
    int source,
    int target) {
      minCount = -1;
      if (source == target) {
        return 0;
      }
      // Cache build
      // key: station number value: [line1, line2]
      unordered_map<int, unordered_set<int>> stationCache;
      for (int i = 0; i < routes.size(); i++) {
        for (int j = 0; j < routes[i].size(); j++) {
          stationCache[routes[i][j]].insert(i);
        }
      }
      unordered_set<int> startLines = stationCache[source];
      unordered_set<int> endLines = stationCache[target];
      for (auto startLine : startLines) {
        if (endLines.find(startLine) != endLines.end()) {
          return 1;
        }
      }
      // Bfs
      vector<int> lineVec;
      unordered_map<int, int> visited;
      for (auto startLine : startLines) {
        lineVec.push_back(startLine);
        visited[startLine] = 1;
      }
      while (!lineVec.empty()) {
        int topLine = lineVec[0];
        lineVec.erase(lineVec.begin());
        for (auto station : routes[topLine]) {
          for (auto changeableLine : stationCache[station]) {
            // visited
            if (visited.find(changeableLine) != visited.end()) {
              continue;
            }
            // find match
            if (endLines.find(changeableLine) != endLines.end()) {
              updateMinValue(visited[topLine] + 1);
              visited[changeableLine] = visited[topLine] + 1;
              break;
            } else {
              // normal down
              visited[changeableLine] = visited[topLine] + 1;
              lineVec.push_back(changeableLine);
            }
          }
        }
      }
      return minCount;
  }

  void updateMinValue(int current) {
    if (minCount == -1) {
      minCount = current;
    } else {
      minCount = min(minCount, current);
    }
  }
};

/**
*[[10,13,22,28,32,35,43],[2,11,15,25,27],[6,13,18,25,42],[5,6,20,27,37,47],[7,11,19,23,35],[7,11,17,25,31,43,46,48],[1,4,10,16,25,26,46],[7,11],[3,9,19,20,21,24,32,45,46,49],[11,41]]
* 37
* 43
*/
int main() {
  vector<vector<int>> test = {{10, 13, 22, 28, 32, 35, 43},
                              {2, 11, 15, 25, 27},
                              {6, 13, 18, 25, 42},
                              {5, 6, 20, 27, 37, 47},
                              {7, 11, 19, 23, 35},
                              {7, 11, 19, 23, 35},
                              {7, 11, 17, 25, 31, 43, 46, 48},
                              {1, 4, 10, 16, 25, 26, 46},
                              {7, 11},
                              {3, 9, 19, 20, 21, 24, 32, 45, 46, 49}, 
                              {11, 41}};
  Solution solve;
  int result = solve.numBusesToDestination(test, 37, 43);
  return 0;
}