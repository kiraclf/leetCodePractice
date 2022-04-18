#include <string>
#include <vector>
using namespace std;
class Solution {
 public:
  vector<int> numberOfLines(vector<int>& widths, string s) {
    int currentRowCount = 0;
    int currentIndex = 0;
    int rowCount = 1;
    int lastRowCount = 0;
    while (currentIndex < s.size()) {
      int nextCount = widths[s[currentIndex] - 'a'];
      if (currentRowCount + nextCount <= 100) {
        currentRowCount += nextCount;
      } else {
        rowCount++;
        currentRowCount = nextCount;
      }
      lastRowCount = currentRowCount;
      currentIndex++;
    }
    return {rowCount, lastRowCount};
  }
};