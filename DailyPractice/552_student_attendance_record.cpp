#include <vector>
using namespace std;
class Solution {
 public:
  int checkRecord(int n) {
    if ( n == 0) {
      return 0;
    } else if (n == 1) {
      return 3;
    } else if (n == 2) {
      return 8;
    }
    // dp[x][y][z] x -- 当前的天数 | y -- 缺勤的天数 | z -- 后两位的情况 --> 符合标准的个数
    vector<int> zVec(6, 0);
    vector<vector<int>> yVec(n, zVec);
    vector<vector<vector<int>>> dp(n + 1, yVec);
    // 初始化 n = 3 时的数据
    for (int y = 0; y < 2; y++) {
      for (int z = 0; z < 6; z++) {
        dp[3][y][z] = 
      }
    }

  }
};