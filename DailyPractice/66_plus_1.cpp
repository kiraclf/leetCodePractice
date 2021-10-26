#include <vector>
using namespace std;

class Solution {
 public:
  vector<int> plusOne(vector<int>& digits) {
    bool upgrade = false;
    for (int i = digits.size() - 1; i >= 0; i--) {
      if (i == digits.size() - 1) {
        plusOne(digits, i, upgrade);
      } else {
        // handle upgrade.
        if (upgrade) {
          plusOne(digits, i, upgrade);
        } else {
          // no upgrade
          break;
        }
      }
    }
    if (upgrade) {
      digits.insert(digits.begin(), 1);
    }
    return digits;
  }

  void plusOne(vector<int>& numbers, int index, bool& upgrade) {
    // plus one.
    int nextValue = numbers[index] + 1;
    if (nextValue >= 10) {
      nextValue -= 10;
      upgrade = true;
    } else {
      upgrade = false;
    }
    numbers[index] = nextValue;
  }
};