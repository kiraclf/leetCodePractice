#include <vector>
using namespace std;
class Solution {
 public:
  int findPeakElement(vector<int>& nums) {
    int startIndex = 0;
    int endIndex = nums.size() - 1;
    while (startIndex <= endIndex) {
      int midIndex = startIndex + (endIndex - startIndex) / 2;
      int nextValue = (midIndex + 1) < nums.size() ? nums[midIndex + 1] : INT_MIN;
      int beforeValue = (midIndex - 1) < 0 ? INT_MIN : nums[midIndex - 1];
      if (nums[midIndex] > nextValue && nums[midIndex] > beforeValue) {
        return midIndex;
      } else if (nums[midIndex] < nextValue) {
        startIndex = midIndex + 1;
      } else {
        endIndex = midIndex - 1;
      }
    }
    return 0;
  }
};