#include <vector>
using namespace std;
class Solution {
 public:
  int peakIndexInMountainArray(vector<int>& arr) {
    int startIndex = 0;
    int endIndex = arr.size() - 1;
    while (startIndex < endIndex) {
      int midIndex = startIndex + (endIndex - startIndex) / 2;
      int midValue = arr[midIndex];
      int before = 0;
      if (midIndex - 1 > 0) {
        before = arr[midIndex - 1];
      }
      int after = 0;
      if (midIndex + 1 < arr.size() - 1) {
        after = arr[midIndex + 1];
      }
      if (midValue > before && midValue  > after) {
        return midIndex;
      } else if (midValue > before && midValue < after) {
        startIndex = midIndex + 1;
      } else {
        endIndex = midIndex - 1;
      }
    }
    return startIndex;
  }
};

int main() {
  Solution solve;
  vector<int> test = {3,5,3,2,0};
  int result = solve.peakIndexInMountainArray(test);
  return 0;
}