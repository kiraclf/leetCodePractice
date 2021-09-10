#include <vector>
#include <unordered_set>
using namespace std;
struct Investment {
  int profit;
  int capital;
  int id;
};

class Solution {
 public:
  int findMaximizedCapital(
    int k, // 最多的事件
    int w, // 当前的资本
    vector<int>& profits, // 利润
    vector<int>& capital) { // 成本
      unordered_set<int> visited;
      int current = w;
      for (int i = 0; i < k; i++) {
        int index = findMaxIndex(current, visited, profits, capital);
        if (index == -1) {
          return current;
        } else {
          current += profits[index];
          visited.insert(index);
        }
      }
      return current;
    }

    int findMaxIndex(int currentW, unordered_set<int>& visited, vector<int>& profits, vector<int>& capitals) {
      vector<int> possibleIndex;
      for (int i = 0; i < capitals.size(); i++) {
        if (capitals[i] <= currentW) {
          if (visited.find(i) == visited.end()) {
            possibleIndex.push_back(i);
          }
        }
      }
      int resIndex = -1;
      for (auto index : possibleIndex) {
        if (resIndex == -1) {
          resIndex = index;
        } else {
          resIndex = profits[index] > profits[resIndex] ? index : resIndex;
        }
      }
      return resIndex;
    }
};