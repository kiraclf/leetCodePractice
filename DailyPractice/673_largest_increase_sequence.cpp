#include <vector>
using namespace std;
class Solution {
 public:
  int findNumberOfLIS(vector<int>& nums) {
    // dp[i][j] 表示 以 i 结尾的, 长度为 j 的序列的个数 (j <= i)
    // dp[0][0] = 0; dp[0][1] = 1; dp[1][1] = 1;
    // dp[i][j]
    vector<vector<int>> dp(nums.size(), vector<int>(nums.size() + 1, 0));
    int maxLength = 1;
    for (int i = 0; i < dp.size(); i++) {
      dp[i][1] = 1;
    }
    for (int i = 1; i < dp.size(); i++) {
      for (int j = maxLength - 1; j <= maxLength + 1; j++) {
        int count = 0;
        for (int z = 0; z < i; z++) {
          if (nums[z] < nums[i] && (j - 1) <= z + 1 && (j -1) >= 0) {
            count += dp[z][j-1];
            if (count != 0) {
              maxLength = max(maxLength, j);
            }
          }
        }
        dp[i][j] += count;
      }
    }
    int totalCount = 0;
    for (int i = 0; i < dp.size(); i++) {
      totalCount += dp[i][maxLength];
    }
    return totalCount;
  }
};

int main() {
  Solution solve;
  vector<int> test = {1,3,5,4,7};
  int result = solve.findNumberOfLIS(test);
  return 0;
}