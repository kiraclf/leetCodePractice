#include <vector>
using namespace std;
/*
两个整数的 汉明距离 指的是这两个数字的二进制数对应位不同的数量。
计算一个数组中，任意两个数之间汉明距离的总和。
*/
class Solution {
 public:
  int totalHammingDistance(vector<int>& nums) {
    int totalSize = nums.size();
    vector<int> dp(totalSize+1, 0);
    for (int i = 1; i < dp.size(); i++) {
      int currentSum = dp[i-1];
      for (int j = 0; j < i-1; j++) {
        currentSum += getDistance(nums[i-1], nums[j]);
      }
      dp[i] = currentSum;
    }
    return dp[totalSize];
  }

/// 官方题解,对每个位上的汉明距离分别进行计算 ---- 其实还是比较难想到....
  int official(vector<int>& nums) {
    int ans = 0, n = nums.size();
    for (int i = 0; i < 30; ++i) {
      int c = 0;
      for (int val : nums) {
        c += (val >> i) & 1;
      }
      ans += c * (n - c);
    }
    return ans;
  }

  int getDistance(int x, int y) {
    int result = 0;
    for (int i = 0; i < 32; i++) {
      int mask = 1 << i;
      if (mask <= x || mask <= y) {
        if ((x & mask) != (y & mask)) {
          result++;
        }
      } else {
        break;
      }
    }
    return result;
  }
};

int main() {
  Solution solve;
  vector<int> test = {4,14,2};
  int result = solve.totalHammingDistance(test);
  return 0;
}