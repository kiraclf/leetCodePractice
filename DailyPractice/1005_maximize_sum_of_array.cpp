#include <vector>
using namespace std;
class Solution {
 public:
  int largestSumAfterKNegations(vector<int>& nums, int k) {
    if (nums.size() == 0) {
      return 0;
    }
    int sum = 0;
    for (auto num : nums) {
      sum += num;
    }
    int count = 0;
    while (count < k) {
      sort(nums.begin(), nums.end());
      sum = sum - nums[0] + (-1 * nums[0]);
      nums[0] *= -1;
      count++;
    }
    return sum;
  }
};

int main() {
  Solution solve;
  vector<int> test = {2, -3, -1, 5, -4};
  int max = solve.largestSumAfterKNegations(test, 2);
  return 0;
}