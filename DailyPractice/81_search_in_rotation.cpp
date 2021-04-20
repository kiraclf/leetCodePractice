#include <vector>
using namespace std;
/*
* 思路: 找出旋转的点,然后在两侧进行二分搜索
*/
class Solution {
 public:
  bool search(vector<int>& nums, int target) {
    int size = nums.size();
    int revserseIndex = 0;
    for (int i = 1; i < size; i++) {
      if (nums[i] < nums[i-1]) {
        revserseIndex = i-1;
        break;
      }
    }
    return binarySearch(nums, 0, revserseIndex - 1, target) || binarySearch(nums, revserseIndex, size - 1, target);
  }

  bool binarySearch(vector<int>& nums, int start, int end, int target) {
    if (target < nums[start] || target > nums[end]) {
      return false;
    }
    while (start <= end) {
      int mid = (start + end) / 2;
      if (target == nums[mid]) {
        return true;
      } else if (target > nums[mid]) {
        start = mid + 1;
      } else {
        end = mid - 1;
      }
    }
    return false;
  }
};