#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;
/**
 * 思路：从前向后遍历数组，同时创建一个缓存的set，边遍历同时边缓存，边查找。
 * 时间复杂度: O(N) 空间复杂度 O(N)
*/

class Solution {
 public:
  vector<int> twoSum(vector<int>& nums, int target) {
    // key value, value index
    unordered_map<int, int> cacheMap;
    for (int i = 0; i < nums.size(); i++) {
      int targetValue = target - nums[i];
      if (cacheMap.find(targetValue) == cacheMap.end()) {  // Can't find cache.
        cacheMap[nums[i]] = i;
      } else {
        return {i, cacheMap[targetValue]};
      }
    }
    return {};  // Empty return.
  }
};

// Test code
int main() {
  vector<int> nums = {2, 7, 11, 15};
  Solution solve = Solution();
  vector<int> result = solve.twoSum(nums, 9);
  for (int i = 0; i < result.size(); i++) {
    cout << result[i] << endl;
  }
  return 0;
}