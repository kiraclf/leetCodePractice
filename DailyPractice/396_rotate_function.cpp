#include <vector>
using namespace std;
class Solution {
 public:
  int maxRotateFunction(vector<int>& nums) {
    if (nums.size() == 1) {
      return 0;
    }
    int totalSum = 0;
    int before = 0;
    int firstIndex = 0;
    int lastIndex = nums.size() - 1;
    for (int i = 0; i < nums.size(); i++) {
      totalSum += nums[i];
      before += i * nums[i];
    }
    int res = before;
    for (int i = 1; i < nums.size(); i++) {
      int firstValue = nums[firstIndex];
      int lastValue = nums[lastIndex];
      before = before + totalSum - nums.size() * lastValue;
      res = max(before, res);
      firstIndex = (firstIndex - 1) < 0 ? (firstIndex - 1 + nums.size())
                                        : (firstIndex - 1);
      lastIndex =
          (lastIndex - 1) < 0 ? (lastIndex - 1 + nums.size()) : (lastIndex - 1);
    }
    return res;
  }
};

int main() {
  Solution solve;
  vector<int> test = {4, 3, 2, 6};
  int res = solve.maxRotateFunction(test);
  return 0;
}