#include <iostream>
#include <vector>

using namespace std;
/**
 * 难点在于 最小的数的范围一定在 1 -> N + 1
 * 之间，因此将该数组当成一个哈希表进行修正
 */

class Solution {
 public:
  int firstMissingPositive(vector<int>& nums) {
    // 将每个数移动到对应的位置上去
    for (int i = 0; i < nums.size(); i++) {
      while (nums[i] > 0 && nums[i] <= nums.size() &&
             nums[nums[i] - 1] != nums[i]) {
        swap(nums, i, nums[i] - 1);
      }
    }
    // 找出不一致的数
    for (int i = 0; i < nums.size(); i++) {
      if (nums[i] != i + 1) {
        return i + 1;
      }
    }
    return nums.size() + 1;
  }

  void swap(vector<int>& nums, int indexA, int indexB) {
    int temp = nums[indexA];
    nums[indexA] = nums[indexB];
    nums[indexB] = temp;
  }
};