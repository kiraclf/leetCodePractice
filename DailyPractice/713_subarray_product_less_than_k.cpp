#include <vector>
using namespace std;
class Solution {
 public:
  int numSubarrayProductLessThanK(vector<int>& nums, int k) {
    int res = 0, p = 1;
    for (int i = 0, j = 0; i < nums.size(); i++) {
      p *= nums[i];
      while (j <= i && p >= k) p /= nums[j++];
      res += i - j + 1;
    }
    return res;
  }

  int numSubarrayProductLessThanKBrutal(vector<int>& nums, int k) {
    int total = 0;
    for (int i = 0; i < nums.size(); i++) {
      int start = i;
      int end = i;
      long long current = 1;
      while (start >= 0) {
        current = current * nums[start];
        if (current >= k) {
          break;
        }
        total++;
        start--;
      }
    }
    return total;
  }
};