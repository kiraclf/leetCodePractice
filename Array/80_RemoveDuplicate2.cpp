// Given a sorted array nums, remove the duplicates in-place such that
// duplicates appeared at most twice and return the new length. Do not allocate
// extra space for another array you must do this by modifying the input array
// in-place with O(1) extra memory.

#include <iostream>
#include <vector>
using namespace std;

/**
 * 思路:
 *  感觉还是模仿 removeDuplicate 1,
 * 唯一不同的地方在于判断重复时，需要多看2个元素
 */

class Solution {
 public:
  int removeDuplicates(vector<int>& nums) {
    // 异常判断，0， 1， 2 直接返回
    if (nums.size() <= 2) return nums.size();
    int valildIndex = 0;
    int nextIndex = 1;
    while (nextIndex < nums.size()) {
      if (nums[nextIndex] != nums[valildIndex]) {
        nums[valildIndex + 1] = nums[nextIndex];
        nextIndex++;
        valildIndex++;
      } else {
        if (valildIndex - 1 >= 0) {
          if (nums[valildIndex - 1] == nums[nextIndex]) {
            nextIndex++;
          } else {
            nums[valildIndex + 1] = nums[nextIndex];
            nextIndex++;
            valildIndex++;
          }
        } else {
          nums[valildIndex + 1] = nums[nextIndex];
          nextIndex++;
          valildIndex++;
        }
      }
    }
    return valildIndex + 1;
  }

  int daShenCode(vector<int>& nums) {
    int i = 0;
    for (int n : nums)
      if (i < 2 || n > nums[i - 2]) nums[i++] = n;
    return i;
  }
};