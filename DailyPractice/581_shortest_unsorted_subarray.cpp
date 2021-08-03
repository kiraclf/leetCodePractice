#include <vector>
using namespace std;
class Solution {
 public:
  int findUnsortedSubarray(vector<int>& nums) {
    // find start first index
    int startIndex = -1;
    for (int i = 0; i < nums.size() - 1; i++) {
      if (nums[i] > nums[i+1]) {
        startIndex = i;
        break;
      }
    }
    if (startIndex == -1) {
      return 0;
    }
    // find end first index
    int endIndex = -1;
    for (int i = nums.size() - 1; i > 0; i--) {
      if (nums[i] < nums[i-1]) {
        endIndex = i;
        break;
      }
    }
    // scan for min and max value
    int unorderedMin = INT_MAX;
    int unorderedMax = INT_MIN;
    for (int i = startIndex; i <= endIndex; i++) {
      unorderedMin = min(nums[i], unorderedMin);
      unorderedMax = max(nums[i], unorderedMax);
    }
    // extend start and end
    while ((startIndex - 1) >= 0 && nums[startIndex - 1] > unorderedMin) {
      startIndex--;
    }
    while ((endIndex + 1) < nums.size() && nums[endIndex + 1] < unorderedMax) {
      endIndex++;
    }
    return endIndex - startIndex + 1;
  }

  int findUnsortedSubarrayBrutal(vector<int>& nums) {
    vector<int> copyed(nums);
    sort(nums.begin(), nums.end());
    int startIndex = -1;
    int endIndex = -1;
    for (int i = 0; i < nums.size(); i++) {
      if (copyed[i] != nums[i]) {
        startIndex = i;
        break;
      }
    }
    for (int i = nums.size() - 1; i >= 0; i--) {
      if (copyed[i] != nums[i]) {
        endIndex = i;
        break;
      }
    }
    if (startIndex == -1 || endIndex == -1) {
      return 0;
    }
    return endIndex - startIndex + 1;
  }
};

int main() { 
  Solution solve;
  vector<int> test = {1,3,2,3,3}; 
  int result = solve.findUnsortedSubarray(test);
  return 0;
  }