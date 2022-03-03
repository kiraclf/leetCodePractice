#include <vector>
using namespace std;
class Solution {
 public:
  int maximumDifference(vector<int>& nums) {
    int result = -1;
    // exception handler.
    if (nums.size() <= 1) {
      return result;
    }
    // before store the minimun value.
    for (int i = 1; i < nums.size(); i++) {
      if (nums[i] > nums[i - 1]) {
        result = max(result, nums[i] - nums[i - 1]);
        nums[i] = nums[i - 1];
      }
    }
    return result;
  }
};

int main() {
  vector<int> test = {1, 5, 2, 10};
  Solution solve;
  int result = solve.maximumDifference(test);
  return 0;
}