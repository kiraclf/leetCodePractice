#include <vector>
using namespace std;
class Solution {
 public:
  int dominantIndex(vector<int>& nums) {
    if (nums.size() == 0) {
      return -1;
    }
    int maxIndex = 0;
    // current max value
    int curretMax = nums[0];
    // current secondary value
    int smallerMax = -1;
    for (int i = 1; i < nums.size(); ++i) {
      int value = nums[i];
      if (value > curretMax) {
        if (value >= curretMax * 2) {
          maxIndex = i;
        } else {
          maxIndex = -1;
        }
        smallerMax = curretMax;
        curretMax = value;
      } else if (value > smallerMax) {
        smallerMax = value;
        if (maxIndex != -1) {
          if (smallerMax * 2 > nums[maxIndex]) {
            maxIndex = -1;
          }
        }
      }
    }
    return maxIndex;
  }
};

int main() {
  Solution solve;
  vector<int> test = {0, 0, 3, 2};
  int res = solve.dominantIndex(test);
  return 0;
}