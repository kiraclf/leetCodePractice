#include <vector>
using namespace std;
class Solution {
 public:
  int minMoves(vector<int>& nums) {
    int count = 0;
    int minValue = INT_MAX;
    for (int i = 0; i < nums.size(); i++) {
      minValue = min(nums[i], minValue);
    }
    for (int i = 0; i < nums.size(); i++) {
      count += (nums[i] - minValue);
    }
    return count;
  }
};

int main() {
  Solution solve;
  vector<int> test = {1, 2, 3, 7, 8, 9};
  int count = solve.minMoves(test);
  return 0;
}