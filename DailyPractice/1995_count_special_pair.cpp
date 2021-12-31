#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
 public:
  int countQuadruplets(vector<int>& nums) {
    int count = 0;
    // value -- maxIndex
    unordered_map<int, vector<int>> numMap;
    for (int i = 0; i < nums.size(); i++) {
      numMap[nums[i]].push_back(i);
    }
    for (int aIndex = 0; aIndex < nums.size(); aIndex++) {
      for (int bIndex = aIndex + 1; bIndex < nums.size(); bIndex++) {
        for (int cIndex = bIndex + 1; cIndex < nums.size(); cIndex++) {
          int targetValue = nums[aIndex] + nums[bIndex] + nums[cIndex];
          if (numMap.find(targetValue) != numMap.end()) {
            vector<int> zIndexVec = numMap[targetValue];
            for (auto zIndex : zIndexVec) {
              if (zIndex > cIndex) {
                count++;
              }
            }
          }
        }
      }
    }
    return count;
  }
};