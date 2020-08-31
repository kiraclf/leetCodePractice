#include <iostream>
#include <vector>

using namespace std;

/**
 * 思路:
 *  思路与移除重复元素相同，只是只需要判断一个数的值(双指针)
 */
class Solution {
 public:
  int removeElement(vector<int>& nums, int val) {
    int startIndex = 0;
    int nextIndex = 0;
    while (nextIndex < nums.size()) {
      if (nums[nextIndex] == val) {
        nextIndex++;
      } else {
        nums[startIndex] = nums[nextIndex];
        startIndex++;
        nextIndex++;
      }
    }
    return startIndex;
  }
};