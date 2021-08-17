#include <vector>
using namespace std;
class Solution {
 public:
  int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
    // dpArr [x][y][maxMove] = count
    vector<int> move(maxMove + 1, 0);
    vector<vector<int>> y(n, move);
    vector<vector<vector<int>>> dp(m, y);
    int mod = 1000000007;
    // maxMove = 1 init
    for( int step = 1; step <= maxMove; step++) {
    for (int y = 0; y < dp[0].size(); y++) {
      if (y == 0 || y == dp[0].size() - 1) {
        dp[0][y][step] = 2;
        dp[dp.size() - 1][y][step] = 2;
      } else {
        dp[0][y][step] = 1;
        dp[dp.size() - 1][y][step] = 1;
      }
    }
    }
    for (int x = 1; x < dp.size() - 1; x++) {
      dp[x][0][1] = 1;
      dp[x][dp[x].size() - 1][1] = 1;
    }
    // dp
    for (int step = 2; step <= maxMove; step++) {
      for (int x = 0; x < dp.size(); x++) {
        for (int y = 0; y < dp[x].size(); y++ ) {
          // 上
          if (x > 0) {
            dp[x][y][step] += (dp[x-1][y][step-1] % mod);
            dp[x][y][step] = dp[x][y][step] % mod;
          }
          // 下
          if (x < dp.size() - 1) {
            dp[x][y][step] += (dp[x+1][y][step-1] % mod);
            dp[x][y][step] = dp[x][y][step] % mod;
          }
          // 左
          if (y > 0) {
            dp[x][y][step] += (dp[x][y-1][step-1] % mod);
            dp[x][y][step] = dp[x][y][step] % mod;
          }
          // 右
          if (y < dp[x].size() - 1) {
            dp[x][y][step] += (dp[x][y+1][step-1] % mod );
            dp[x][y][step] = dp[x][y][step] % mod;
          }
        }
      }
    }
    return dp[startRow][startColumn][maxMove];
  }
};