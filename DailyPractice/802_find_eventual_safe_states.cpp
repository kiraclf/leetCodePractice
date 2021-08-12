#include <vector>
#include <unordered_set>
using namespace std;
class Solution {
 public:
  vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
    // find safe set
    unordered_set<int> safeSet;
    unordered_set<int> dangerSet;
    for (int i = 0; i < graph.size(); i++) {
      if (graph[i].size() == 0) {
        safeSet.insert(i);
      }
      
    }
    //
  }
};