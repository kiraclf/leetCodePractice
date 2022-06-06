#include <algorithm>
#include <string>
#include <unordered_set>
#include <vector>
using namespace std;
class Solution {
 public:
  int findSubstringInWraproundString(string p) {
    vector<int> dp(26);
    int k = 0;
    for (int i = 0; i < p.length(); ++i) {
      if (i && (p[i] - p[i - 1] + 26) % 26 == 1) {  // 字符之差为 1 或 -25
        ++k;
      } else {
        k = 1;
      }
      dp[p[i] - 'a'] = max(dp[p[i] - 'a'], k);
    }
    int res = 0;
    for (auto dpItem : dp) {
      res += dpItem;
    }
    return res;
  }
};

int main() {
  Solution solve;
  string test = "zab";
  int result = solve.findSubstringInWraproundString(test);
  return 0;
}