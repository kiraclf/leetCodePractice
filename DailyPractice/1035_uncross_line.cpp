#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
 public:
  int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
    int max = 0;
    // generate nums2 cache
    unordered_map<int, vector<int>> nums2Cache;
    for (int i = 0; i < nums2.size(); i++) {
      if (nums2Cache.find(nums2[i]) == nums2Cache.end()) {
        nums2Cache[nums2[i]] = {i};
      } else {
        nums2Cache[nums2[i]].push_back(i);
      }
    }
    // connected index list
    dfs(0, nums1, -1, nums2Cache, 0, max);
    return max;
  }

  void dfs(
    int index, 
  vector<int> &nums1, 
  int before, 
  unordered_map<int,vector<int>> &cacheMap,
  int count,
  int &maxValue) {
    if (index >= nums1.size()) {
      maxValue = max(count, maxValue);
      return;
    }
    // connect all still less than max
    int maxCount = nums1.size() - index;
    if (count + maxCount < maxValue) {
      return;
    }
    // connect
    int rawBefore = before;
    if (cacheMap.find(nums1[index]) != cacheMap.end()) {
      // find match value
      vector<int> toConnectList = cacheMap[nums1[index]];
      if (before == -1) {
        // no connected line use the smallest value
        before = toConnectList[0];
        dfs(index+1, nums1, before, cacheMap, count + 1, maxValue);
      } else {
        // find the smallest value larger than before
        int targetIndex = -1;
        for (auto index : toConnectList) {
          if (index > before) {
            targetIndex = index;
            break;
          }
        }
        if (targetIndex != -1) {
          dfs(index+1, nums1, targetIndex, cacheMap, count + 1,maxValue);
        }
      }
    }
    before = rawBefore;
    // not connect
    dfs(index + 1, nums1, before, cacheMap, count,maxValue);
  }
};