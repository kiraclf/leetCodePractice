#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
 public:
  int countKDifference(vector<int>& nums, int k) {
    if (nums.size() <= 1) {
      return 0;
    }
    int count = 0;
    unordered_map<int, int> numMap;
    numMap[nums[0]] += 1;
    for (int i = 1; i < nums.size(); ++i) {
      int less = nums[i] - k;
      int bigger = nums[i] + k;
      count += numMap[less];
      count += numMap[bigger];
      numMap[nums[i]] += 1;
    }
    return count;
  }
};