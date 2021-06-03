#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
 public:
  bool checkSubarraySum(vector<int>& nums, int k) {
    vector<int> sums(nums.size() + 1, 0);
    for (int i = 1; i < sums.size(); i++) {
      sums[i] = sums[i-1] + nums[i-1];
    }
    unordered_map<int, int> cacheMap;
    for (int i = 1; i < sums.size(); i++) {
      if (i > 1 && sums[i] == 0) {
        return true;
      }
      int remain = sums[i] % k;
      sums[i] = remain;
      if ( i > 1 && remain == 0) {
        return true;
      }
      if (cacheMap.find(remain) == cacheMap.end()) {
        cacheMap[remain] = i;
      } else {
        cacheMap[remain] = min(cacheMap[remain], i);
      }
    }
    for (int i = 2; i < sums.size(); i++) {
      if (cacheMap.find(sums[i]) != cacheMap.end()) {
        int index = cacheMap[sums[i]];
        if (i - index > 1) {
          return true;
        }
      }
    }
    return false;
  }
};

int main() {
  Solution solve;
  vector<int> test = {1,0};
  bool resulst = solve.checkSubarraySum(test, 2);
  return 0;
}