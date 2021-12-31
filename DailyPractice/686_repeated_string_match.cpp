#include <string>
#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
 public:
  int repeatedStringMatch(string a, string b) {
    // a character map
    unordered_map<char, vector<int>> aMaps;
    for (int i = 0; i < a.size(); i++) {
      aMaps[a[i]].push_back(i);
    }
    // find b's first index in a
    vector<int> firstPossibleIndex = aMaps[b[0]];
    int minMatch = INT_MAX;
    for (auto firstIndex : firstPossibleIndex) {
      int currentCount = firstIndex == 0 ? 0 : 1;
      int currentIndex = 0;
      bool match = true;
      while (currentIndex < b.size()) {
        int aIndex = (currentIndex + firstIndex) % a.size();
        if (aIndex == 0) {
          currentCount += 1;
        }
        if (a[aIndex] != b[currentIndex]) {
          match = false;
          break;
        }
        currentIndex++;
      }
      if (match) {
        minMatch = min(minMatch, currentCount);
      }
    }
    return minMatch == INT_MAX ? -1 : minMatch;
  }
};

int main() {
  string a = "abc";
  string b = "xyz";
  Solution solve;
  int count = solve.repeatedStringMatch(a, b);
  return 0;
}