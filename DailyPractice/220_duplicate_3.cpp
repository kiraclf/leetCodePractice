#include <vector>
#include <set>
using namespace std;

class Solution {
 public:
  bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
    set<long long> st;
    int left = 0;
    for (int right = 0; right < nums.size(); right++) {
      if (right - left > k) {
        st.erase(nums[left]);
        left++;
      }
      auto a = st.lower_bound((long long)nums[right] - t);
      if (a != st.end() && abs(*a - nums[right]) <= t) {
        return true;
      }
      st.insert(nums[right]);
    }
    return false;
  }
bool brutalSolve(vector<int>& nums, int k, int t) {
    for (int i = 0; i < nums.size(); i++) {
      for (int j = i + 1; j < nums.size() && j <= i + k; j++) {
        long absValue = abs((long)nums[i] - (long)nums[j]);
        if (absValue <= t) {
          return true;
        }
       }
    }
    return false;
  }
};