#include <string>
#include <vector>
using namespace std;
class Solution {
 public:
  vector<int> shortestToChar(string s, char c) {
    vector<int> ans(s.size(), INT_MAX);
    // left c index
    int nearsetLeftIndex = -1;
    for (int i = 0; i < s.size(); i++) {
      if (s[i] != c) {
        if (nearsetLeftIndex != -1) {
          ans[i] = nearsetLeftIndex;
        }
      } else {
        ans[i] = 0;
        nearsetLeftIndex = i;
      }
    }
    int nearsetRightIndex = -1;
    for (int i = s.size() - 1; i >= 0; i--) {
      if (s[i] != c) {
        if (nearsetRightIndex != -1) {
          ans[i] = min(abs(ans[i] - i), abs(nearsetRightIndex - i));
        } else {
          ans[i] = i - ans[i];
        }
      } else {
        nearsetRightIndex = i;
      }
    }
    return ans;
  }
};

int main() {
  Solution solve;
  string s = "aaab";
  char test = 'b';
  auto res = solve.shortestToChar(s, test);
  return 0;
}