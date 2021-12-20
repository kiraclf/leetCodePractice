using namespace std;
class Solution {
 public:
  int numWaterBottles(int numBottles, int numExchange) {
    int count = numBottles;
    int unRewardBottlesCount = numBottles;
    while (unRewardBottlesCount >= numExchange) {
      int changeCount = unRewardBottlesCount / numExchange;
      count += changeCount;
      unRewardBottlesCount -= (changeCount * numExchange);
      unRewardBottlesCount += changeCount;
    }
    return count;
  }
};

int main() {
  Solution solve;
  int res = solve.numWaterBottles(5, 5);
  return 0;
}