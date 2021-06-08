#include <vector>
#include <string>
#include <unordered_set>
using namespace std;
class Solution {
 public:
  int findMaxForm(vector<string>& strs, int m, int n) {
    // 最多 m 个 0, n 个 1 ==> 最长为 m +n, 和 <= n
    // size = 2, default = 0, [size, oneCount];
    vector<vector<int>> cache;
    for (int i = 0; i < strs.size(); i++) {
      vector<int> current(2,0);
      for (int j = 0; j < strs[i].size(); j++) {
        if (strs[i][j] == '1') {
          current[1] += 1;
        } else {
          current[0] += 1;
        }
      }
      cache.push_back(current);
    }
    // dfs
    unordered_set<int> currentSet;
    return maxSize(currentSet, 0, 0, n, m, cache);
  }

  int maxSize(unordered_set<int> &currentList, int currentOne, int currentZero, int maxOne, int maxZero, vector<vector<int>> &cache) {
    int result = 0;
    if (currentZero > maxZero || currentOne > maxOne) {
      return 0;
    } else {
      result = max(result, (int)currentList.size());
    }
    for (int i = 0; i < cache.size(); i++) {
      if (currentList.find(i) == currentList.end()) {
        // can add
        currentList.insert(i);
        result = max(result, maxSize(currentList, currentOne + cache[i][1],
                                     currentZero + cache[i][0], maxOne,
                                     maxZero, cache));
        currentList.erase(i);
      }
    }
    return result;
  }
};

int main() {
  Solution solve;
  vector<string> test = {"10","1", "0"};
  int result = solve.findMaxForm(test, 1,1);
  return 0;
}