#include <vector>
using namespace std;
class Solution {
 public:
  int numSquares(int n) {
    vector<int> dp(n + 1, -1);
    dp[1] = 1;
    dp[0] = 0;
    for (int i = 2; i < dp.size(); i++) {
      for (int j = 1; j <= n; j++) {
        if (i - j * j < 0) {
          break;
        } else {
          if (dp[i] == -1) {
            dp[i] = dp[i - j * j] + 1;
          } else {
            dp[i] = min(dp[i], dp[i - j * j] + 1);
          }
        }
      }
    }
    return dp[n];
  }
};

int main() {
  Solution solve;
  int result = solve.numSquares(13);
  return 0;
}