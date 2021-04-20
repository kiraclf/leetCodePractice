#include <vector>
using namespace std;

class Solution {
 public:
  int removeDuplicates(vector<int>& nums) {
    int size = nums.size();
    if (size <= 1) {
      return size;
    }
    int start = 1;
    int current = 1;
    while (current < size) {
      if (nums[current] != nums[start-1]) {
        // 不重复
        nums[start] = nums[current];
        start++;
      }
      current++;
    }
    return start;
  }
};