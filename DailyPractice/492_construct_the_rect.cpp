#include "vector"
using namespace std;
class Solution {
 public:
  vector<int> constructRectangle(int area) {
    int lesser = 1;
    int space = area - 1;
    vector<int> result = {area, 1};
    while (lesser <= area) {
      if (area % lesser != 0) {
        lesser++;
        continue;
      }
      int larger = area / lesser;
      int currentSpace = larger - lesser;
      if (larger < lesser) {
        break;
      }
      if (currentSpace < space) {
        result = {larger, lesser};
        space = currentSpace;
      }
      lesser++;
    }
    return result;
  }
};