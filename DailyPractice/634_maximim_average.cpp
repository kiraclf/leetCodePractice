#include <vector>
using namespace std;

/*
给定 n 个整数，找出平均数最大且长度为 k 的连续子数组，
输出该最大平均数。
*/

class Solution {
 public:
  double findMaxAverage(vector<int>& nums, int k) {
    int numsSize = nums.size();
    if ( numsSize == 0) {
      return 0.0;
    }
    int maximumSum = INT_MIN;
    int leftIndex = 0;
    int rightIndex = 1;
    int windowSum = nums[leftIndex];
    // init
    while ( rightIndex - leftIndex + 1 <= k && rightIndex < numsSize) {
      windowSum += nums[rightIndex];
      rightIndex++;
    }
    rightIndex--;
    maximumSum = max(windowSum, maximumSum);
    // sliding
    while ( rightIndex < numsSize ) {
      if (leftIndex != 0) {
        windowSum -= nums[leftIndex - 1];
        windowSum += nums[rightIndex];
      }
      maximumSum = max(windowSum, maximumSum);
      rightIndex++;
      leftIndex++;
    }
    return maximumSum * 1.0 / k;
  }
};

int main() {
  vector<int> test = {1, 12, -5, -6, 50, 3};
  Solution solve;
  double result = solve.findMaxAverage(test, 4);
  return 0;
}