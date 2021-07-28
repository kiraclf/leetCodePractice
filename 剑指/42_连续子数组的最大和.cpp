#include <vector>
using namespace std;
class Solution {
 public:
  int maxSubArray(vector<int>& nums) {
    vector<int> sums(nums.size(), 0);
    int beforeMin = 0;
    int result = nums[0];
    for (int i = 0; i < sums.size(); i++) {
      if (i == 0) {
        sums[i] = nums[i];
      } else {
        sums[i] = sums[i-1] + nums[i];
      }
      result = max(result, sums[i] - beforeMin);
      beforeMin = min(beforeMin, sums[i]);
    }
    return result;
  }
};

int main() {
  Solution solve;
  vector<int> test = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
  int result = solve.maxSubArray(test);
  return 0;
}