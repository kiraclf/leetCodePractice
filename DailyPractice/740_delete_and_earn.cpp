#include <vector>
#include <unordered_map>
using namespace std;
/*
* 先使用 dfs,然后记录中间结果进行优化
*/
class Solution {
 public:
  int deleteAndEarn(vector<int>& nums) {
    // 确定max
    int maxValue = 0;
    for (auto number:nums) {
      maxValue = max(number,maxValue);
    }
    maxValue++;
    vector<int> numbers(maxValue, 0);
    for (int i = 0; i < nums.size(); i++) {
      numbers[nums[i]] += nums[i];
    }
    vector<int> dp(maxValue, 0);
    dp[0] = 0;
    dp[1] = numbers[1];
    for (int i = 2; i < numbers.size(); i++) {
      dp[i] = max(dp[i-1], dp[i-2] + numbers[i]);
    }
    return dp[dp.size() - 1];
  }
};