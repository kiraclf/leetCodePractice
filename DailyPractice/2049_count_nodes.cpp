#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
 public:
  int countHighestScoreNodes(vector<int>& parents) {
    // parent map
    unordered_map<int, int> parentMap;
    // child map
    unordered_map<int, vector<int>> childMap;
    for (int i = 0; i < parents.size(); ++i) {
      if (i != 0) {
        parentMap[i] = parents[i];
      }
      if (parents[i] != -1) {
        childMap[parents[i]].push_back(i);
      }
    }
    // cacluate point size.
    vector<int> size(parents.size(), -1);
    size[0] = parents.size();
    dfsLength(0, size, childMap);
    int maxPoint = -1;
    int count = 0;
    for (int i = 0; i < parents.size(); ++i) {
      // top count
      int topCount = 0;
      if (parentMap.find(i) != parentMap.end()) {
        topCount = parents.size() - size[i];
      }
      // left count
      int leftCount = 0;
      vector<int> child = childMap[i];
      if (child.size() != 0) {
        leftCount = size[child[0]];
      }
      // right count
      int rightCount = parents.size() - 1 - topCount - leftCount;
      // sum
      topCount = topCount == 0 ? 1 : topCount;
      leftCount = leftCount == 0 ? 1 : leftCount;
      rightCount = rightCount == 0 ? 1 : rightCount;
      int value = topCount * leftCount * rightCount;
      if (value > maxPoint) {
        maxPoint = value;
        count = 1;
      } else if (value == maxPoint) {
        count += 1;
      }
    }
    return count;
  }

  int dfsLength(int node, vector<int>& sizeList,
                unordered_map<int, vector<int>>& child) {
    if (child[node].size() == 0) {
      sizeList[node] = 1;
      return 1;
    } else {
      int totalCount = 1;
      for (auto childs : child[node]) {
        if (sizeList[childs] != -1) {
          totalCount += sizeList[childs];
        } else {
          totalCount += dfsLength(childs, sizeList, child);
        }
      }
      sizeList[node] = totalCount;
      return totalCount;
    }
  }
};

int main() {
  Solution solve;
  vector<int> parent = {-1, 2, 0, 2, 0};
  int count = solve.countHighestScoreNodes(parent);
  return 0;
}