#include <unordered_set>
#include <vector>
using namespace std;
class Solution {
 public:
  bool increasingTriplet(vector<int>& nums) {
    if (nums.size() < 3) {
      return false;
    }
    unordered_set<int> leftHaveSmallerIndexSet;
    int currentSmallest = nums[0];
    for (int i = 1; i < nums.size(); ++i) {
      if (nums[i] > currentSmallest) {
        leftHaveSmallerIndexSet.insert(i);
      } else {
        currentSmallest = nums[i];
      }
    }
    int currentBiggest = nums[nums.size() - 1];
    for (int i = nums.size() - 2; i >= 0; i--) {
      if (nums[i] < currentBiggest) {
        if (leftHaveSmallerIndexSet.find(i) != leftHaveSmallerIndexSet.end()) {
          return true;
        }
      } else {
        currentBiggest = nums[i];
      }
    }
    return false;
  }
};

int main() {
  Solution solve;
  vector<int> test = {2, 1, 5, 0, 4, 6};
  bool res = solve.increasingTriplet(test);
  return 0;
}