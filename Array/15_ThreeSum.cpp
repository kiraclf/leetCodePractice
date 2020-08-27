#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

/****************************************
 * 思路:
 * 类似 twoSum, 使用两层循环 + 一个 cache 来寻找
 * 空间复杂度 O(N)
 * 时间复杂度 O(N ^ 2)
 *****************************************/

class Solution {
 public:
  vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> res;
    // 数组排序
    sort(nums.begin(), nums.end());
    // 固定一个数的值
    for (int i = 0; i < nums.size(); i++) {
      int target = -nums[i];
      int front = i + 1;
      int back = nums.size() - 1;
      while (front < back) {
        int sum = nums[front] + nums[back];
        if (sum < target) {
          front++;
        } else if (sum > target) {
          back--;
        } else {
          vector<int> vaildateV = {nums[i], nums[front], nums[back]};
          res.push_back(vaildateV);
          while (front < back && nums[front + 1] == vaildateV[1]) front++;
          while (front < back && nums[back - 1] == vaildateV[2]) back--;
          front++;
          back--;
        }
      }
      // 忽略重复的 number 1
      while (i + 1 < nums.size() && nums[i + 1] == nums[i]) {
        i++;
      }
    }
    return res;
  }
};

int main() {
  vector<int> test = {-1, 0, 1, 2, -1, -4};
  Solution solve = Solution();
  vector<vector<int>> ans = solve.threeSum(test);
  for (auto list : ans) {
    for (auto index : list) {
      cout << index << " " << endl;
    }
    cout << "/n" << endl;
  }
  return 0;
}