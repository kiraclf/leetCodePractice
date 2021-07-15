#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
 public:
  int numSubarraysWithSum(vector<int>& nums, int goal) {
    // create prefix sum vec.
    vector<int> sums(nums.size(), 0);
    for (int i = 0; i < nums.size(); i++) {
      if (i == 0) {
        sums[i] = nums[0];
      } else {
        sums[i] = sums[i-1] + nums[i];
      }
    }
    // cache map
    unordered_map<int ,int> countMap;
    countMap[0] = 1;
    int count = 0;
    for (int i = 0; i < sums.size(); i++) {
      int target = sums[i] - goal;
      if (countMap.find(target) != countMap.end()) {
        count += countMap[target];
      }
      countMap[sums[i]] += 1; 
    }
    return count;
  }
};

int main() {
  Solution solve;
  vector<int> test = {0, 0, 0, 0, 0};
  int target = 0;
  int result = solve.numSubarraysWithSum(test, target);
  return 0;
}