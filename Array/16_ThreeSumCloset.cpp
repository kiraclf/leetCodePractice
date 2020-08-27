#include <iostream>
#include <vector>

using namespace std;
/**
 * 思路:
 * 1.Brutal Force:
 *  直接三层循环，寻找最接近的数值 空间复杂度 O(1) 时间复杂度 O(N^3)
 * 2.类似 ThreeSum ，先排序，然后进行比较
 *  sum == target 直接返回
 *  sum < target left++
 *  sum > target right--
 *  如果出现一次交替 --> 到达临界点 --> 比较两次的值返回最小的值 (可选比较)
 *  空间复杂度 O(N) 或者 O(logN) 取决于排序的算法 时间复杂度 O(N^2)
 */

class Solution {
 public:
  int threeSumClosest(vector<int>& nums, int target) {
    sort(nums.begin(), nums.end());
    // 这里直接使用 result = INT_MAX
    // 后续会有溢出，此处直接赋值一个随机值，反正是找出最接近值，其实是无所谓的
    // int result = INT_MAX;
    int result = nums[0] + nums[1] + nums[2];
    for (int i = 0; i < nums.size(); i++) {
      int leftIndex = i + 1;
      int rightIndex = nums.size() - 1;
      while (leftIndex < rightIndex) {
        int sum = nums[i] + nums[leftIndex] + nums[rightIndex];
        if (sum == target) {
          return target;
        } else if (sum < target) {
          if (abs(sum - target) < abs(result - target)) {
            result = sum;
          }
          leftIndex++;
        } else {
          if (abs(sum - target) < abs(result - target)) {
            result = sum;
          }
          rightIndex--;
        }
      }
    }
    return result;
  }
};

int main() {
  vector<int> test = {-1, 2, 1, -4};
  Solution solve = Solution();
  int result = solve.threeSumClosest(test, 1);
  cout << "result:" << result << endl;
  return 0;
}