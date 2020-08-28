#include <iostream>
#include <vector>

using namespace std;
/*
  给定一个排序数组，你需要在 原地
  删除重复出现的元素，使得每个元素只出现一次，返回移除后数组的新长度。
  不要使用额外的数组空间，你必须在 原地 修改输入数组 并在使用 O(1)
  额外空间的条件下完成。
 */

class Solution {
 public:
  int removeDuplicates(vector<int>& nums) {
    // 特殊判断
    if (nums.size() == 1) return 1;
    int startIndex = 0;
    int count = 0;
    while (startIndex < nums.size()) {
      nums[count] = nums[startIndex];
      count++;
      while (startIndex + 1 < nums.size() &&
             (nums[startIndex] == nums[startIndex + 1])) {
        startIndex++;
      }
      startIndex++;
    }
    // remove duplicate
    for (int i = 0; i < nums.size() - count; i++) {
      nums.pop_back();
    }
    return count;
  }

  int removeDuplicate(vector<int>& nums) {
    if (nums.size() == 0) return 0;
    int i = 0;
    for (int j = 1; j < nums.size(); j++) {
      if (nums[j] != nums[i]) {
        i++;
        nums[i] = nums[j];
      }
    }
    return i + 1;
  }
};

int main() {
  vector<int> testList = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
  Solution solve = Solution();
  int count = solve.removeDuplicates(testList);
  cout << "Count:" << count << endl;
  return 0;
}