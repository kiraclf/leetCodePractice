#include <vector>
using namespace std;
class Solution {
 public:
  int peakIndexInMountainArray(vector<int>& arr) {
    int startIndex = 1;
    int endIndex = arr.size() - 2;
    while (startIndex <= endIndex) {
      int midIndex = startIndex + (endIndex - startIndex) / 2;
      if (arr[midIndex] > arr[midIndex - 1] && arr[midIndex] > arr[midIndex + 1]) {
        return midIndex;
      }
      if (arr[midIndex] > arr[midIndex - 1]) {
        startIndex = midIndex + 1;
      } else {
        endIndex = midIndex - 1;
      }
    }
    return -1; // can't find
  }
};

int main () {
  Solution solve;
  vector<int> test = {1,3,5,4,2};
  int result = solve.peakIndexInMountainArray(test);
  return 0;
}