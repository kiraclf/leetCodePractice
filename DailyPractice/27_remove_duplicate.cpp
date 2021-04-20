#include <vector>
using namespace std;
class Solution {
 public:
  int removeElement(vector<int>& nums, int val) {
    int start = 0;
    int current = 0;
    int size = nums.size();
    while (current < size) {
      int currentValue = nums[current];
      if (currentValue != val) {
        // 不重复
        nums[start] = currentValue;
        start++;
      }
      current++;
    }
    return start;
  }
};