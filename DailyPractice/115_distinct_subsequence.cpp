#include <string>
using namespace std;
class Solution {
 public:
  int numDistinct(string s, string t) {
    int count = 0;
    dfs(s, t, 0,count, 0);
    return count;
  }

  void dfs(string text, 
          string pattern, 
          int index, 
          int &count, 
          int targetIndex) {
    if (targetIndex == pattern.size()) {
      count++;
      return;
    }
    if (index >= text.size()) {
      return;
    }
    for (int i = index; i < text.size(); i++) {
      if (text[i] == pattern[targetIndex]) {
        dfs(text, pattern, i+1, count, targetIndex + 1);
      }
    }
  }
};

int main() {
  Solution solve;
  int result = solve.numDistinct("babgbag", "bag");
  return 0;
}