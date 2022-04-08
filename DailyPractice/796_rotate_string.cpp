#include <string>
using namespace std;
class Solution {
 public:
  bool rotateString(string s, string goal) {
    if (s.size() != goal.size()) {
      return false;
    }
    for (int i = 0; i < goal.size(); i++) {
      if (goal[i] != s[0]) {
        continue;
      }
      bool match = true;
      for (int j = 1; j < s.size(); j++) {
        int goalIndex = (i + j) % goal.size();
        if (goal[goalIndex] != s[j]) {
          match = false;
          break;
        }
      }
      if (match) {
        return match;
      }
    }
    return false;
  }
};