#include <iostream>
#include <vector>

using namespace std;

/**
 * 思路 Brutal:
 *  直接利用3重循环，找到合适的值，然后进行去重
 *  麻烦的地方在于去重，4个数，时间复杂度较高
 *
 * 思路 threeSum:
 *  1. 先将数组排序
 *  2. 固定第一个数 i 和第二个 i + 1
 *  3. 头指针 i + 2, 尾指针 last
 *  4. 移动 i + 1 到另一个不同的数的位置
 *
 * 可以优化的点：
 *  在部分地方直接进行取和的判断，可以跳过部分结果 --- 减枝
 */
class Solution {
 public:
  vector<vector<int>> fourSum(vector<int>& nums, int target) {
    vector<vector<int>> ans;
    // 1.Sort
    sort(nums.begin(), nums.end());
    int firstIndex = 0;
    // 2. 固定 firstIndex
    while (firstIndex < nums.size()) {
      int secondIndex = firstIndex + 1;
      // 3. 固定 secondIndex
      while (secondIndex < nums.size()) {
        int startIndex = secondIndex + 1;
        int endIndex = nums.size() - 1;
        while (startIndex < endIndex) {
          int currentSum = nums[firstIndex] + nums[secondIndex] +
                           nums[startIndex] + nums[endIndex];
          if (currentSum == target) {
            ans.push_back({nums[firstIndex], nums[secondIndex],
                           nums[startIndex], nums[endIndex]});
            // startIndex jump to an different value
            while (startIndex < endIndex &&
                   (nums[startIndex] == nums[startIndex + 1])) {
              startIndex++;
            }
            startIndex++;
          } else if (currentSum < target) {
            // add startIndex to different index
            while (startIndex < endIndex &&
                   (nums[startIndex] == nums[startIndex + 1])) {
              startIndex++;
            }
            startIndex++;
          } else {
            // substract endIndex to differnt index
            while (startIndex < endIndex &&
                   (nums[endIndex] == nums[endIndex - 1])) {
              endIndex--;
            }
            endIndex--;
          }
        }
        // Second index to different index
        while (secondIndex + 1 < nums.size() &&
               (nums[secondIndex] == nums[secondIndex + 1])) {
          secondIndex++;
        }
        secondIndex++;
      }
      // First index to different index
      while (firstIndex + 1 < nums.size() &&
             (nums[firstIndex] == nums[firstIndex + 1])) {
        firstIndex++;
      }
      firstIndex++;
    }
    // Return
    return ans;
  }
};

int main() {
  vector<int> toTest = {1, 0, -1, 0, -2, 2};
  Solution solve = Solution();
  vector<vector<int>> ans = solve.fourSum(toTest, 0);
  for (auto list : ans) {
    for (auto value : list) {
      cout << value << ", ";
    }
    cout << "/n" << endl;
  }
  return 0;
}
