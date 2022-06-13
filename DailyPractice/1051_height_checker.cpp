#include <vector>
using namespace std;
class Solution {
 public:
  int heightChecker(vector<int>& heights) {
    vector<int> heightArr(101, 0);
    for (auto height : heights) {
      heightArr[height]++;
    }
    int currentIndex = 0;
    int equalCount = 0;
    for (int i = 0; i < heightArr.size(); i++) {
      if (heightArr[i] == 0) {
        continue;
      } else {
        for (int j = currentIndex; j < currentIndex + heightArr[i]; j++) {
          if (heights[j] == heightArr[i]) {
            equalCount++;
          }
        }
        currentIndex += heightArr[i];
      }
    }
    return heights.size() - equalCount;
  }
};