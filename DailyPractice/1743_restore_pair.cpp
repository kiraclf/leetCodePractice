#include <vector>
#include <unordered_map>
#include <set>
using namespace std;
class Solution {
 public:
  vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
    vector<int> res(adjacentPairs.size() + 1, 0);
    unordered_map<int, vector<int>> map;
    for (auto pair : adjacentPairs) {
      map[pair[0]].push_back(pair[1]);
      map[pair[1]].push_back(pair[0]);
    }
    vector<int> beginAndEnd;
    for (auto pair : map) {
      if (pair.second.size() == 1) {
        beginAndEnd.push_back(pair.first);
      }
    }
    res[0] = beginAndEnd[0];
    res[1] = map[beginAndEnd[0]][0];
    res[res.size() - 1] = beginAndEnd[1];
    for (int i = 2; i < res.size() - 1; i++) {
      int before = res[i-1];
      int beforeBefore = res[i-2];
      vector<int> beforeSib = map[before];
      for (auto value : beforeSib) {
        if (value != beforeBefore) {
          res[i] = value;
        }
      }
    }
    return res;
  }
};

int main() {
  Solution solve;
  vector<vector<int>> test = {{2,1}, {3,4}, {3,2}};
  vector<int> list = solve.restoreArray(test);
  return 0;
}