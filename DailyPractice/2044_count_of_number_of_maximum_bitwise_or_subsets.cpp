#include <vector>
using namespace std;
class Solution {
 private:
  int totalCount;
  int maxValue;
  vector<int> nums;

 public:
  int countMaxOrSubsets(vector<int>& nums) {
    totalCount = 0;
    maxValue = -1;
    this->nums = nums;
    for (int i = 0; i < nums.size(); i++) {
      if (nums[i] > this->maxValue) {
        this->maxValue = nums[i];
        this->totalCount = 1;
      } else if (nums[i] == this->maxValue) {
        this->totalCount += 1;
      }
      dfs(nums[i], i + 1);
    }
    return totalCount;
  }

  void dfs(int currentOrValue, int index) {
    if (index >= this->nums.size()) {
      return;
    }
    // choose
    int currentValue = currentOrValue | this->nums[index];
    if (currentValue == this->maxValue) {
      this->totalCount++;
    } else if (currentValue > this->maxValue) {
      this->maxValue = currentValue;
      this->totalCount = 1;
    }
    dfs(currentValue, index + 1);
    dfs(currentOrValue, index + 1);
  }
};

int main() {
  Solution solve;
  vector<int> test = {2, 2, 2};
  int count = solve.countMaxOrSubsets(test);
  return 0;
}