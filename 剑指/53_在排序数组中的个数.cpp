#include <vector>
using namespace std;
class Solution {
 public:
  int search(vector<int>& nums, int target) {
    
  }

  int binarySearchSmallestIndexLargerOrEqualToTarget(vector<int>& nums, int target) {
    int startIndex = 0;
    int endIndex = nums.size() - 1;
    while (startIndex <= endIndex) {
      int midIndex = startIndex + (endIndex - startIndex) / 2;
      if (nums[midIndex] < target) {
        startIndex = midIndex + 1;
      } else {
        endIndex = midIndex;
      }
    }
  }
};