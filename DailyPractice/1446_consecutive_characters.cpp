#include <string>
using namespace std;
class Solution {
 public:
  int maxPower(string s) {
    if (s.size() == 0) {
      return 0;
    }
    int power = 1;
    int currentCount = 1;
    int index = 1;
    char before = s[0];
    while (index < s.size()) {
      if (s[index] == before) {
        currentCount++;
      } else {
        before = s[index];
        currentCount = 1;
      }
      power = max(power, currentCount);
      index++;
    }
    return power;
  }
};

int main() {
  Solution solve;
  string test = "aa";
  int res = solve.maxPower(test);
  return 0;
}