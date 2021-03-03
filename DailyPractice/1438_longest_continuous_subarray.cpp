#include <vector>
#include <deque>
using namespace std;
/*
给你一个整数数组 nums ，和一个表示限制的整数limit
请返回最长连续子数组的长度，该子数组中的任意两个元素之间的绝对差必须小于或者等于limit
如果不存在满足条件的子数组，则返回 0

--- 总结
此处的问题,在于滑动时的状态保存
* 使用红黑树
* 使用两个单调栈进行保存
*/

class Solution {
 public:
  int longestSubarray(vector<int>& nums, int limit) {
    // exception check
    int size = nums.size();
    if (size == 0) {
      return 0;
    }
    // init
    deque<int> queMax, queMin;
    // sliding window
    int left = 0;
    int right = 0;
    int maxCount = 0;
    while (right < size) {
      while (!queMax.empty() && queMax.back() < nums[right]) {
        queMax.pop_back();
      }
      while (!queMin.empty() && queMin.back() > nums[right]) {
        queMin.pop_back();
      }
      queMax.push_back(nums[right]);
      queMin.push_back(nums[right]);
      while (!queMax.empty() && !queMin.empty() && queMax.front() - queMin.front() > limit) {
        if (nums[left] == queMin.front()) {
          queMin.pop_front();
        } 
        if (nums[left] == queMax.front()) {
          queMax.pop_front();
        }
        left++;
      }
      maxCount = max(maxCount, right - left + 1);
      right++;
    }
    return maxCount;
  }
};