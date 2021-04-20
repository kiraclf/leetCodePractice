#include <vector>
using namespace std;
class Solution {
 public:
  int findMin(vector<int>& nums) {
    int minValue = INT_MAX;
    int start = 0;
    int end = nums.size() -1;
    while (start <= end) {
      int mid = (start + end) / 2;
      if (nums[mid] > nums[0]) {
        // 左侧有序
        minValue = min(minValue, nums[start]);
        start = mid + 1;
      } else {
        // 右侧有序
        minValue = min(minValue, nums[mid]);
        end = mid - 1;
      }
    }
    return minValue;
  }
};