#include <vector>
using namespace std;
class Solution {
 public:
  int numberOfArithmeticSlices(vector<int>& nums) {
    int size = nums.size();
    if (size < 3) {
      return 0;
    }
    // check first pair nums[0] nums[1] nums[2]
    int result = 0;
    int current = 0;
    if (canFormatAirthmeticWithBefore(nums, 2)) {
      current++;
      result += current;
    }
    for (int i = 3; i < size; i++) {
      if (canFormatAirthmeticWithBefore(nums, i)) {
        current = current + 1;
        result += current;
      } else {
        current = 0;
      }
    }
    return result;
  }

  bool canFormatAirthmeticWithBefore(vector<int>& nums, int index) {
    if (index - 2 < 0) {
      return false;
    }
    if ((nums[index] - nums[index - 1]) == (nums[index - 1] - nums[index - 2])) {
      return true;
    } else {
      return false;
    }
  }
};

int main() {
  Solution solve;
  vector<int> result = {1};
  int count = solve.numberOfArithmeticSlices(result);
  return 0;
}