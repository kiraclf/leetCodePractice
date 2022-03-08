#include <vector>
using namespace std;
class Solution {
 public:
  int minimumDifference(vector<int>& nums, int k) {
    if (k == 1) {
      return 0;
    }
    int res = INT_MAX;
    sort(nums.begin(), nums.end());
    for (int i = k - 1; i < nums.size(); i++) {
      int currentMin = nums[i] - nums[i - k + 1];
      res = min(res, currentMin);
    }
    return res;
  }
};

int main() {
  Solution solve;
  vector<int> test = {90};
  int k = 1;
  int res = solve.minimumDifference(test, k);
  return 0;
}