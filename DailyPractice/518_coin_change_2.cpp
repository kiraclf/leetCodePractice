#include <vector>
using namespace std;
class Solution {
 public:
  int change(int amount, vector<int>& coins) {
    // 设置 dp[i][j] 表示在使用前i个硬币的情况下,可以凑成j的个数
    int coinSize = coins.size();
    vector<int> amountVec(amount + 1, 0);
    vector<vector<int>> dp(coinSize + 1, amountVec);
    // Init.
    for (int i = 0; i < dp.size(); i++) {
      dp[i][0] = 1;
    }
    // Dp caculate
    for (int i = 1; i < dp.size(); i++) {
      for (int j = 0; j < dp[0].size(); j++) {
        dp[i][j] = dp[i-1][j];
        int currentValue = coins[i-1];
        for (int k = 1; j - currentValue * k >= 0; k++) {
          dp[i][j] += dp[i - 1][j - currentValue * k];
        }
      }
    }
    return dp[coinSize][amount];
  }
};

int main() {
  Solution solve;
  vector<int> coins = {10};
  int result = solve.change(10, coins);
  return 0;
}