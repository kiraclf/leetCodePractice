#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;
class Solution {
 public:
  int networkDelayTime(vector<vector<int>>& times, int n, int k) {
    // 创建一个距离的数组表示从起点到对应点的距离 默认为 INT_MAX 表示不连通
    vector<int> distanceVec(n + 1, INT_MAX);
    unordered_set<int> relaxedSet;
    // 初始化 distanceVec
    relaxedSet.insert(k);
    distanceVec[k] = 0;
    for (auto time : times) {
      if (time[0] == k) {
        distanceVec[time[1]] = time[2];
      }
    }
    // Relax each point 
    while (relaxedSet.size() < n) {
      int smallestIndex = -1;
      int smallDistance = INT_MAX;
      // the smallest point
      for (int i = 1; i < distanceVec.size(); i++) {
        if (relaxedSet.find(i) == relaxedSet.end()) {
          if (distanceVec[i] < smallDistance) {
            smallestIndex = i;
            smallDistance = distanceVec[i];
          }
        }
      }
      if (smallestIndex == -1) {
        break;
      }
      // realxed smallIndex
      for (auto time : times) {
        if (time[0] == smallestIndex) {
          distanceVec[time[1]] = min(distanceVec[time[1]], distanceVec[time[0]] + time[2]);
        }
      }
      relaxedSet.insert(smallestIndex);
    }
    // Get answer
    int maxValue = 0;
    for (int i = 1; i < distanceVec.size(); i++) {
      maxValue = max(maxValue, distanceVec[i]);
    }
    if (maxValue == INT_MAX) {
      return -1;
    }
    return maxValue;
  }
};

int main() {
  Solution solve;
  vector<vector<int>> test = {{1,2,1}};
  int res = solve.networkDelayTime(test, 2, 2);
  return 0;
}