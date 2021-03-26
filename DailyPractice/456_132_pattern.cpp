#include <vector>
using namespace std;

class Solution {
 public:
 /*
 * 确定中间值,左侧使用贪心使用最小值,遍历右侧
 */
  bool find132pattern(vector<int>& nums) {
    int size = nums.size();
    if (size < 3) {
      return false;
    }
    vector<int> smallest(size, 0);
    int currentSmallest = INT_MAX;
    for (int i = 0; i < size; i++) {
      smallest[i] = nums[i] < currentSmallest ? nums[i] : currentSmallest;
    }
    for (int j = 1; j < size - 1; j++) {
      for (int k = j + 1; k < size; k++) {
        if (smallest[j-1] < nums[k] && nums[k] < nums[j]) {
          return true;
        }
      }
    }
    return false;
  }

  bool findOfficial(vector<int> &nums) {
    int size = nums.size();
    if (size < 3) return false;
    vector<int> stack = {nums[size-1]};
    int last = INT_MIN;
    for (int i = size - 2; i >= 0; i--) {
      int current = nums[i];
      if (current < last) return true;
      while (stack.size() && current > stack[stack.size() - 1]) {
        last = stack.back();
        stack.pop_back();
      }
      // 找到对应的次小值
      if (current > last) stack.push_back(current);
    }
    return false;
  }
};

int main() {
  Solution slove;
  vector<int> test = {1, 0, 1, -4, 3};
  bool result = slove.find132pattern(test);
  return 0;
}