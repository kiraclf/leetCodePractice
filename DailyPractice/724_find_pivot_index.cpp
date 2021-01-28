/**
给定一个整数类型的数组 nums，请编写一个能够返回数组 “中心索引” 的方法。

我们是这样定义数组 中心索引
的：数组中心索引的左侧所有元素相加的和等于右侧所有元素相加的和。

如果数组不存在中心索引，那么我们应该返回
-1。如果数组有多个中心索引，那么我们应该返回最靠近左边的那一个。
*/

#include <stdio.h>

#include <string>
#include <vector>
using namespace std;

class Solution {
 public:
  // 思路: 建立一个左侧和数组, 建立一个右侧和数组然后直接比较
  int pivotIndex(vector<int>& nums) {
    int size = nums.size();
    if (size == 0) {
      return -1;
    }
    vector<int> leftSum(size, 0);
    vector<int> rightSum(size, 0);
    for (int i = 1; i < size; i++) {
      leftSum[i] = leftSum[i - 1] + nums[i - 1];
    }
    for (int i = size - 2; i >= 0; i--) {
      rightSum[i] = rightSum[i + 1] + nums[i + 1];
    }
    for (int i = 0; i < size; i++) {
      if (leftSum[i] == rightSum[i]) {
        return i;
      }
    }
    return -1;
  }

  int pivotImpoved(vector<int>& nums) {
    // 其实这里,左侧和右侧值的数组是可以省略的
    int total = 0;
    for (int i = 0; i < nums.size(); i++) {
      total += nums[i];
    }
    int leftSum = 0;
    for (int i = 0; i < nums.size(); i++) {
      if ((2 * leftSum) == total - nums[i]) {
        return i;
      } else {
        leftSum += nums[i];
      }
    }
    return -1;
  }
};

int main() {
  vector<int> test;
  test.push_back(1);
  test.push_back(7);
  test.push_back(3);
  test.push_back(6);
  test.push_back(5);
  test.push_back(6);
  Solution solve;
  int result = solve.pivotIndex(test);
  return 0;
}