#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
 public:
  int findPairs(vector<int>& nums, int k) {
    int totalCount = 0;
    unordered_map<int, vector<int>> pairMap;
    if (nums.size() <= 1) {
      return 0;
    }
    pairMap[nums[0]] = {};
    for (int i = 1; i < nums.size(); i++) {
      int less = nums[i] - k;
      int bigger = nums[i] + k;
      if (pairMap.find(less) != pairMap.end()) {
        if (pairMap[less].size() == 0) {
          totalCount += 1;
          pairMap[less].push_back(nums[i]);
        }
      }
      if (pairMap.find(bigger) != pairMap.end()) {
        if (pairMap[nums[i]].size() == 0) {
          totalCount += 1;
          pairMap[nums[i]].push_back(bigger);
        }
      }
      pairMap[nums[i]] = pairMap[nums[i]];
    }
    return totalCount;
  }
};