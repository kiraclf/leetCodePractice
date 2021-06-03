#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
 public:
  int findMaxLength(vector<int>& nums) {
    unordered_map<int, int> cache;
    cache[0] = -1;
    int result = 0;
    for (int i = 0; i < nums.size(); i++) {
      if (nums[i] == 0) {
        nums[i] = -1;
      }
      if (i > 0) {
        nums[i] = nums[i-1] + nums[i];
        if (cache.find(nums[i]) == cache.end()) {
          cache[nums[i]] = i;
        } else {
          result = max(result, i-cache[nums[i]]);
        }
      } else {
        cache[nums[i]] = i;
      }
    }
    return result;
  }
};

int main() {
  Solution solve;
  vector<int> test = {1};
  int result = solve.findMaxLength(test);
  return 0;
}