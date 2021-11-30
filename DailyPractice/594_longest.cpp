#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
 public:
  int findLHS(vector<int>& nums) {
    // Dp Solution.
    int size = nums.size();
    // K - value V - count
    unordered_map<int, int> cache;
    // dp(n) = max(dp(n-1), dp(n));
    vector<int> dp(size, 0);
    for (int i = 0; i < dp.size(); i++) {
      if (i == 0) {
        cache[nums[i]] += 1;
        continue;
      }
      int value = nums[i];
      cache[value] += 1;
      int tempRes = 0;
      if (cache.find(value - 1) != cache.end()) {
        // Less than 1 exist
        tempRes = max(tempRes, cache[value - 1] + cache[value]);
      }
      if (cache.find(value + 1) != cache.end()) {
        // Larger than 1 exit
        tempRes = max(tempRes, cache[value + 1] + cache[value]);
      }
      dp[i] = max(dp[i - 1], tempRes);
    }
    return dp[size - 1];
  }
};

int main() {
  Solution solve;
  vector<int> test = {1, 1, 1, 1};
  int max = solve.findLHS(test);
  return 0;
}