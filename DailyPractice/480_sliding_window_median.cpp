/*
中位数是有序序列最中间的那个数。
如果序列的大小是偶数，则没有最中间的数；
此时中位数是最中间的两个数的平均数。

例如：
[2,3,4]，中位数是 3
[2,3]，中位数是 (2 + 3) / 2 = 2.5
给你一个数组 nums，有一个大小为 k 的窗口从最左端滑动到最右端。窗口中有 k
个数，每次窗口向右移动 1
位。你的任务是找出每次窗口移动后得到的新窗口中元素的中位数，并输出由它们组成的数组。
*/
#include <vector>
using namespace std;
class Solution {
 public:
  vector<double> medianSlidingWindow(vector<int>& nums, int k) {
    vector<double> result;
    // odd get average value, even get middle value
    bool odd = k % 2 == 0;
    // init window
    vector<double> window;
    for (int i = 0; i < nums.size() - k; i++) {
      if (window.size() < k) {
        window.push_back(nums[i]);
      } else {
        // caculate median
        // push and restore
        for (int i = k - 1; i >= 1; i--) {
          window[i] = window[i-1];
        }
        window[k-1] = nums[i];
      }
    }
    return result;
  }
};
