#include <unordered_set>
using namespace std;
class Solution {
 public:
  bool judgeSquareSum(int c) {
    // square list
    unordered_set<int> numberSet;
    int number = 0;
    long max = 0;
    while (max <= c) {
      if (number > INT32_MAX / INT16_MAX) {
        break;
      }
      int value = number * number;
      if (value <= c) {
        numberSet.insert(value);
        max = value;
        number++;
      } else {
        break;
      }
    }
    // find
    for (auto number : numberSet) {
      int target = c - number;
      if (numberSet.find(target) != numberSet.end()) {
        // find
        return true;
      }
    }
    return false;
  }
};

int main() {
  Solution solve;
  bool result = solve.judgeSquareSum(3);
  return 0;
}