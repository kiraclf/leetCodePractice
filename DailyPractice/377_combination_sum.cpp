#include <vector>
using namespace std;

class Solution {
 private:
  int target;
  vector<int> nums;

 public:
  int combinationSum4(vector<int>& nums, int target) {
    this->target = target;
    this->nums = nums;
    int count = 0;
    // 异常处理
    if (nums.size() == 0 || target <= 0) {
      return 0;
    }
    // DFS
    for (int i = 0; i < nums.size(); i++) {
        dfs(0, i, count);
    }
    return count;
  }

  void dfs(int current, int index, int& count) {
    // terminator
    int size = nums.size();
    // out of bounds
    if (index >= size) {
      return;
    }
    // out of target
    if (current > target) {
      return;
    }
    // process
    current += nums[index];
    printf("%i value: %i \n", index, nums[index]);
    if (current > target) {
        printf("---\n");
      return;
    } else if (current == target) {
      count++;
      printf("count++\n");
      return;
    } else {
      // next
      for (int i = 0; i < size; i++) {
        dfs(current, i, count);
      }
    }
  }
};

int main() {
  vector<int> test = {1, 2, 3};
  Solution solve;
  int result = solve.combinationSum4(test, 4);
  return 0;
}