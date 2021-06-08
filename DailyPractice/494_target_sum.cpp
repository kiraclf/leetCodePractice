#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
 public:
  int findTargetSumWays(vector<int>& nums, int target) {
    // Construct dp array.
    int length = nums.size();
    // -20000 -> 20000
    int targetSize = 40001;
    // key : value , value: Count
    unordered_map<int, int> before;
    unordered_map<int, int> current;
    // first line init
    if (nums.size() > 0) {
      int first = nums[0];
      if (first == 0) {
        before[first] = 2;
      } else {
        before[first] = 1;
        before[-first] = 1;
      }
    }
    // dp
    for (int i = 1; i < nums.size(); i++) {
     for (auto beforeResult : before) {
       if (beforeResult.second != 0) {
         int adds = nums[i] + beforeResult.first;
         int minus = beforeResult.first - nums[i];
         current[adds] += beforeResult.second;
         current[minus] += beforeResult.second;
       }
     }
     unordered_map<int, int> temp = before;
     before = current;
     current = temp;
     current.clear();
    }
    return before[target];
  }
};

int main() {
  Solution solve;
  vector<int> test = {0, 0, 0, 0, 0, 0, 0, 0, 1};
  int result = solve.findTargetSumWays(test, 1);
  return 0;
}