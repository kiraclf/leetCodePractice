#include <vector>
using namespace std;
/*
给你一个长度为 n 的整数数组，请你判断在 最多 改变 1
个元素的情况下，该数组能否变成一个非递减数列。

我们是这样定义一个非递减数列的： 对于数组中所有的 i (0 <= i <= n-2)，总满足
nums[i] <= nums[i + 1]。
--思路--
1. 使用一个头指针,遍历
2. 如果匹配则向前进
3. 如果不匹配,则: 1. 查看前面的值是否 <= 后面的值 否则直接返回 false 2. 不匹配数+1
*/

class Solution {
 public:
  bool checkPossibility(vector<int>& nums) {
    int cnt = 0;
    for (int i = 1; i < nums.size() && cnt < 2; i++) {
      if (nums[i] >= nums[i-1]) {
        continue;
      }
      cnt++;
      if ( i - 1 > 0 && nums[i] < nums[i-2]) {
        nums[i] = nums[i-1];
      } else {
        nums[i-1] = nums[i];
      }
    }
    return cnt <= 1;
  }
};

int main() {
  vector<int> nums = {-1,4,2,3};
  Solution solve;
  bool result = solve.checkPossibility(nums);
  return 0;
}