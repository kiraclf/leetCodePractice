#include <unordered_set>
using namespace std;
class Solution {
 public:
  bool checkPerfectNumber(int num) {
    unordered_set<int> divisors;
    int totalDiv = 1;
    for (int i = 2; i < num; i++) {
      if (divisors.find(i) != divisors.end()) {
        break;
      }
      if (num % i == 0) {
        divisors.insert(i);
        divisors.insert(num / i);
        if (i == (num / i)) {
          totalDiv += i;
        } else {
          totalDiv += i;
          totalDiv += (num / i);
        }
      }
    }
    return totalDiv == num;
  }
};

int main() {
  Solution solve;
  int num = 7;
  bool res = solve.checkPerfectNumber(num);
  return 0;
}