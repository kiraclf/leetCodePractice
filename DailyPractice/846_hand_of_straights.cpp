#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
 public:
  bool isNStraightHand(vector<int>& hand, int groupSize) {
    if (hand.size() % groupSize != 0) {
      return false;
    }
    int groupCount = hand.size() / groupSize;
    sort(hand.begin(), hand.end());
    // key: card, value: count
    unordered_map<int, int> cardMap;
    for (auto card : hand) {
      cardMap[card] += 1;
    }
    // pair generate
    int currentStartIndex = 0;
    for (int i = 0; i < groupCount; i++) {
      int startValue = hand[currentStartIndex];
      for (int j = startValue; j <= startValue + groupSize - 1; j++) {
        if (cardMap[j] - 1 < 0) {
          return false;
        }
        cardMap[j] -= 1;
      }
      while (currentStartIndex < hand.size() &&
             cardMap[hand[currentStartIndex]] == 0) {
        currentStartIndex++;
      }
      if (currentStartIndex == hand.size() && i != groupCount - 1) {
        return false;
      }
    }
    return true;
  }
};

int main() {
  vector<int> hand = {1};
  int groupSize = 1;
  Solution solve;
  bool res = solve.isNStraightHand(hand, groupSize);
  return 0;
}