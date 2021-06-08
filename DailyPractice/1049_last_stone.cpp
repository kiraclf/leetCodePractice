#include <vector>
using namespace std;

class Solution {
 public:
  int lastStoneWeightII(vector<int>& stones) {
    int size = stones.size();
    int sum = 0;
    for (auto stone : stones) {
      sum += stone;
    }
    // dp[i][j] 前 i 个,总和不超过 j 的最大值
    vector<int> sumVector(sum / 2 + 1, 0);
    vector<vector<int>> dp(size + 1, sumVector);
    // dp 处理
    for (int i = 1; i <= stones.size(); i++) {
      for (int j = 0; j <= sum / 2; j++) {
        dp[i][j] = dp[i-1][j];
        if (j >= stones[i-1]) {
          dp[i][j] = max(dp[i][j], dp[i-1][j-stones[i-1]] + stones[i-1]);
        }        
      }
    }
    return abs(sum  - dp[size][sum/2] - dp[size][sum/2]);
  }
};

int main() {
  Solution solve;
  vector<int> test = {31, 26, 33, 21, 40};
  int result = solve.lastStoneWeightII(test);
  return 0;
}