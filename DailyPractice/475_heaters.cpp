#include <vector>
using namespace std;
class Solution {
 public:
  int findRadius(vector<int>& houses, vector<int>& heaters) {
    int minRadius = 1;
    int maxRadius = 30004;
    int res = maxRadius;
    while (minRadius <= maxRadius) {
      int midRadius = minRadius + ((maxRadius - minRadius) >> 1);
      bool canAllBeHeated = true;
      for (auto house : houses) {
        if (!canBeHeated(house, heaters, midRadius)) {
          canAllBeHeated = false;
          break;
        }
      }
      if (canAllBeHeated) {
        res = min(res, midRadius);
        maxRadius = midRadius - 1;
      } else {
        minRadius = midRadius + 1;
      }
    }
    return res;
  }

  bool canBeHeated(int house, vector<int>& heaters, int radius) {
    int startIndex = 0;
    int endIndex = heaters.size() - 1;
    while (startIndex <= endIndex) {
      int midIndex = startIndex + ((endIndex - startIndex) >> 1);
      int heatLocation = heaters[midIndex];
      if (heatLocation - radius <= house && heatLocation + radius >= house) {
        // can be heat
        return true;
      } else if (heatLocation + radius < house) {
        startIndex = midIndex + 1;
      } else {
        endIndex = midIndex - 1;
      }
    }
    return false;
  }
};

int main() {
  Solution solve;
  vector<int> houses = {1, 2, 3, 4};
  vector<int> heaters = {1, 4};
  int res = solve.findRadius(houses, heaters);
  return 0;
}