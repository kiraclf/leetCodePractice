#include <vector>
using namespace std;
class Solution {
 public:
  int search(vector<int>& nums, int target) {
    if (nums.size() == 0) {
      return -1;
    }
    int startIndex = 0;
    int endIndex = nums.size() - 1;
    while (startIndex <= endIndex) {
      int midIndex = startIndex + (endIndex - startIndex) / 2;
      if (nums[midIndex] == target) {
        return midIndex;
      } else if (nums[midIndex] > target) {
        endIndex = midIndex - 1;
      } else {
        startIndex = midIndex + 1;
      }
    }
    return -1;
  }
};