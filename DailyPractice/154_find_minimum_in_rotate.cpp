#include <vector>
using namespace std;

class Solution {
 public:
  int findMin(vector<int>& nums) {
    int size = nums.size();
    int start = 0;
    int end = size - 1;
    int result = INT_MAX;
    while (start <= end) {
      int mid = start + (end - start) / 2;
      if (nums[mid] > nums[start]) {
        // 左侧有序
        result = min(nums[start], result);
        start = mid;
      } else if (nums[mid] < nums[end]) {
        // 右侧有序
        result = min(nums[mid], result);
        end = mid - 1;
      } else if (nums[mid] == nums[start] && nums[mid] == nums[end]) {
        // 全部相同
        result = min(nums[mid], result);
        start++;
        end--;
      } else if (nums[mid] <= nums[start]) {
        // 右侧有序
        result = min(nums[mid], result);
        end = mid - 1;
      } else {
        // 左侧有序
        result = min(nums[start], result);
        start = mid;
      }
    }
    return result;
  }
};