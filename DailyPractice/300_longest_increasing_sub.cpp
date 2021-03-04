#include <vector>
#include <string>
using namespace std;
class Solution {
 public:
  int lengthOfLIS(vector<int>& nums) {
    int size = nums.size();
    vector<int> dp(size, 1);
    for (int i = 1; i < nums.size(); i++) {
      for (int j = 0; j < i; j++) {
        if (nums[i] > nums[j]) {
          dp[i] = max(dp[j] + 1, dp[i]);
        } else {
          dp[i] = dp[i];
        }
      }
    }
    int maxValue = 0;
    for (auto value : dp) {
      maxValue = max(value, maxValue); 
    }
    return maxValue;
  }
};