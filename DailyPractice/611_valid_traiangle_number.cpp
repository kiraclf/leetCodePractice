#include <vector>
using namespace std;
class Solution {
 public:
  int triangleNumber(vector<int>& nums) {
    // exception
    if (nums.size() < 3) {
      return 0;
    }
    // sort arr
    sort(nums.begin(), nums.end());
    // for in loop use binary search
    int count = 0;
    for (int i = 0; i < nums.size() - 2; i++) {
      if (nums[i] == 0) {
        continue;
      }
      for (int j = i + 1; j < nums.size() - 1; j++) {
        if (nums[j] == 0) {
          continue;
        }
        int largerIndex = binarySearchLessThanRightIndex(nums, nums[i] + nums[j]);
        if (largerIndex != -1) {
          count += largerIndex - j;
        }
      }
    }
    return count;
  }

  // if can't find index, return -1
  int binarySearchLessThanRightIndex(vector<int> &nums, int target) {
    int startIndex = 0;
    int endIndex = nums.size() - 1;
    if (nums[startIndex] >= target) {
      return -1;
    }
    if (nums[endIndex] < target) {
      return endIndex;
    }
    int ansIndex = 0;
    while (startIndex <= endIndex) {
      int midIndex = startIndex + (endIndex - startIndex) / 2;
      if (nums[midIndex] >= target) {
        endIndex = midIndex - 1;
      } else {
        ansIndex = midIndex;
        startIndex = midIndex + 1;
      }
    }
    return ansIndex;
  }
};

int main() {
  Solution solve;
  vector<int> test = {2,2,3,4};
  int count = solve.triangleNumber(test);
  return 0;
}