#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
 public:
  int maxFrequency(vector<int>& nums, int k) {
    int size = nums.size();
    sort(nums.begin(), nums.end());
    // 前缀和
    vector<int> sum(size + 1, 0);
    for (int i = 1; i <= size; i++) {
      sum[i] = sum[i-1] + nums[i-1];
    }
    // 滑动区间(最小长度,最大长度)
    int left = 0, right = size;
    while (left < right) {
      int mid = left + (right - left) / 2;
      if (check(mid, nums, sum, k)) {
        left = mid;
      } else {
        right = mid - 1;
      }
    }
    return right;
  }

  bool check(
    int len, 
  vector<int>& nums, 
  vector<int>& sum,
  int cost) {
    // 遍历左侧
    for (int left = 0; left + len - 1 < nums.size(); left++) {
      int right = left + len - 1;
      int current = sum[right + 1] - sum[left];
      int target = nums[right] * len;
      if ( target - current <= cost) return true;
    }
    return false;
  }

  int maxFrequencyBrutail(vector<int>& nums, int k) {
    int size = nums.size();
    unordered_map<int, int> cache;
    for (auto num : nums) {
      cache[num] += 1;
    }
    int ans = 1;
    vector<int> keyList;
    for (auto cac : cache) {
      keyList.push_back(cac.first);
    }
    sort(keyList.begin(), keyList.end());
    for (int i = 0; i < keyList.size(); i++) {
      int key = keyList[i];
      int currentCount = cache[key];
      if ( i > 0) {
        int cost = k;
        for (int j = i - 1; j >= 0; j--) {
          int y = keyList[j];
          int diff = key - y;
          if ( cost >= diff) {
            int add = cost / diff;
            int minCount = min(cache[y], add);
            cost -= minCount * diff;
            currentCount += minCount;
          } else {
            break;
          }
        }
      } 
      ans = max(ans, currentCount);
    }
    return ans;
  }
};