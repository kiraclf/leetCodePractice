#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
 public:
  bool containsNearbyDuplicate(vector<int>& nums, int k) {
    // key: value, value: maxIndex
    unordered_map<int, int> cache;
    for (int i = 0; i < nums.size(); ++i) {
      int number = nums[i];
      if (cache.find(number) != cache.end()) {
        int largestIndex = cache[number];
        if (i - largestIndex <= k) {
          return true;
        }
        cache[number] = i;
      } else {
        cache[number] = i;
      }
    }
    return false;
  }
};

int main() {
  Solution solve;
  vector<int> test = {1, 2, 3, 1, 2, 3};
  int k = 2;
  bool result = solve.containsNearbyDuplicate(test, k);
  return 0;
}