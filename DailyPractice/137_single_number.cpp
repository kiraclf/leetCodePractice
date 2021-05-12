#include <vector>
#include <unordered_map>
using namespace std;
/*
给你一个整数数组 nums ，除某个元素仅出现一次外，其余每个元素都恰出现三次。
请你找出并返回那个只出现了一次的元素。
*/
class Solution {
 public:
  int singleNumber(vector<int>& nums) {

  }

  int brutalSingleNumber(vector<int>& nums) {
    unordered_map<int, int> cache;
    for (auto &num : nums) {
      if (cache.find(num) == cache.end()) {
        cache[num] = 1;
      } else {
        cache[num] += 1;
      }
    }
    for (auto &cacheItem: cache) {
      if (cacheItem.second == 1) {
        return cacheItem.first;
      }
    }
    // can't find
    return 0;
  }
};