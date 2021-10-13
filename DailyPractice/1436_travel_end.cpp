#include <string>
#include <unordered_set>
#include <vector>
using namespace std;
class Solution {
 public:
  string destCity(vector<vector<string>>& paths) {
    unordered_set<string> starts;
    unordered_set<string> ends;
    for (auto path : paths) {
      starts.insert(path[0]);
      ends.insert(path[1]);
    }
    for (auto start : starts) {
      ends.erase(start);
    }
    for (auto end : ends) {
      return end;
    }
    // will not enter.
    return "";
  }
};