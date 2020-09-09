#include <iostream>
#include <vector>

using namespace std;

/**
 * 思路:
 *  建立一个前缀和数组，然后找出其中的最大值
 */

class Solution {
 public:
  int maxSubArray(vector<int>& nums) {
    if (nums.size() == 0) return 0;
    int beforeSum = nums[0];
    int maxValue = nums[0];
    for (int i = 1; i < nums.size(); i++) {
      beforeSum = max(beforeSum + nums[i], nums[i]);
      maxValue = max(beforeSum, maxValue);
    }
    return maxValue;
  }
};