#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
 public:
  int findRepeatNumber(vector<int>& nums) {
    unordered_set<int> cache;
    for (auto number : nums) {
      if (cache.find(number) == cache.end()) {
        cache.insert(number);
      } else {
        return number;
      }
    }
    return 0;
  }
};