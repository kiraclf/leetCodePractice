#include <algorithm>
class Solution {
 public:
  int trailingZeroes(int n) {
    int twoCount = 0;
    int fiveCount = 0;
    for (int i = 1; i <= n; i++) {
      int temp = i;
      while (temp % 2 == 0) {
        temp = temp / 2;
        twoCount++;
      }
      temp = i;
      while (temp % 5 == 0) {
        temp = temp / 5;
        fiveCount++;
      }
    }
    return std::min(twoCount, fiveCount);
  }
};

int main() {
  Solution solve;
  int reust = solve.trailingZeroes(10000);
  return 0;
}