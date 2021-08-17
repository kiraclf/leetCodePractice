#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;
class Solution {
 public:
  int unhappyFriends(int n, vector<vector<int>>& preferences,vector<vector<int>>& pairs){
    unordered_map<int, int> pairsMap;
    unordered_set<int> visited;
    unordered_set<int> unhappySet;
    for (auto pair : pairs) {
      pairsMap[pair[0]] = pair[1];
      pairsMap[pair[1]] = pair[0];
    }
    for (auto pair : pairsMap) {
      if (visited.find(pair.first) != visited.end()) {
        continue;
      }
      vector<int> pref = preferences[pair.first];
      for (int i = 0; i < pref.size(); i++) {
        if (pref[i] == pair.second) {
          break;
        }
        vector<int> anOtherPre = preferences[pref[i]];
        int pairNumber = pairsMap[pref[i]];
        bool unHappy = false;
        for (int i = 0; i < anOtherPre.size(); i++) {
          if (anOtherPre[i] == pair.first) {
            unHappy = true;
            break;
          } else if (anOtherPre[i] == pairNumber) {
            break;
          }
        }
        if (unHappy) {
          unhappySet.insert(pref[i]);
          unhappySet.insert(pair.first);
          visited.insert(pref[i]);
        }
        visited.insert(pair.first);
      }
    }
    return (int)unhappySet.size();
  }
};

int main() {
  vector<vector<int>> prefs = {{1,3,2}, {2,3,0}, {1,3,0}, {0,2,1}};
  vector<vector<int>> pairs = {{1,3}, {0,2},};
  Solution solve;
  int unhappyCount = solve.unhappyFriends(4,prefs, pairs);
  return 0;
}