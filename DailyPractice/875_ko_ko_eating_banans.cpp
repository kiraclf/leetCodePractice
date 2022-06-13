#include <vector>
using namespace std;
class Solution {
 private:
  vector<int> piles;
  int h;

 public:
  int minEatingSpeed(vector<int>& piles, int h) {
    sort(piles.begin(), piles.end());
    this->piles = piles;
    this->h = h;
    int lowSpeed = 1;
    int maxSpeed = piles[piles.size() - 1];
    while (lowSpeed <= maxSpeed) {
      int mid = lowSpeed + (maxSpeed - lowSpeed) / 2;
      if (!canEatInTime(mid)) {
        lowSpeed = mid + 1;
      } else {
        maxSpeed = mid - 1;
      }
    }
    return lowSpeed;
  }

  bool canEatInTime(int speed) {
    int needTime = 0;
    for (auto pile : piles) {
      needTime += (pile / speed);
      if (pile % speed != 0) {
        needTime += 1;
      }
      if (needTime > h) {
        return false;
      }
    }
    return true;
  }
};

int main() {
  Solution solve;
  vector<int> test = {30, 11, 23, 4, 20};
  int h = 6;
  int res = solve.minEatingSpeed(test, h);
  return 0;
}