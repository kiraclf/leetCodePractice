#include <string>
#include <unordered_set>
using namespace std;
class Solution {
 public:
  bool buddyStrings(string s, string goal) {
    int sSize = s.size();
    int gSize = goal.size();
    if (sSize != gSize) {
      return false;
    }
    int sMissChar = -1;
    int gMissChar = -1;
    int missCount = 0;
    bool hasDuplicate = false;
    unordered_set<char> characters;
    for (int i = 0; i < sSize; i++) {
      if (characters.find(s[i]) != characters.end()) {
        hasDuplicate = true;
      } else {
        characters.insert(s[i]);
      }
      if (s[i] != goal[i]) {
        if (missCount > 2) {
          return false;
        }
        if (sMissChar == -1) {
          sMissChar = goal[i];
          gMissChar = s[i];
          missCount += 1;
        } else {
          if (sMissChar == s[i] && gMissChar == goal[i]) {
            missCount += 1;
          } else {
            return false;
          }
        }
      }
    }
    if ((missCount == 0) && hasDuplicate) {
      return true;
    }
    return missCount == 2;
  }
};

int main() {
  Solution solve;
  bool result = solve.buddyStrings("aa", "aa");
  return 0;
}