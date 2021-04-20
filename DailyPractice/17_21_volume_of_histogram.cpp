#include <vector>
#include <string>
using namespace std;
class Solution {
 public:
  int trap(vector<int>& height) {
    int size = height.size();
    vector<int> leftMax(size, 0);
    vector<int> rightMax(size, 0);
    // init left max
    int leftMaxValue = 0;
    for (int i = 0; i < size; i++) {
      leftMax[i] = leftMaxValue;
      leftMaxValue = max(leftMaxValue, height[i]);
    }
    // init right max
    int rightMaxValue = 0;
    for (int i = size - 1; i >= 0; i--) {
      rightMax[i] = rightMaxValue;
      rightMaxValue = max(rightMaxValue, height[i]);
    }
    // caculate sum
    int res;
    for (int i = 0; i < size; i++) {
      if (leftMax[i] == 0 || rightMax[i] == 0) {
        continue;
      }
      int currentHeight = min(leftMax[i], rightMax[i]);
      if (height[i] >= currentHeight) {
        continue;
      } else {
        res += currentHeight - height[i];
      }
    }
    return res;
  }
};

int main() {
  Solution slove;
  vector<int> test = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
  int result  = slove.trap(test);
  return 0;
}