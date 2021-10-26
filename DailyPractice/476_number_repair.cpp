#include <string>
using namespace std;
class Solution {
 public:
  int findComplement(int num) {
    string current = "";
    while (num != 0) {
      int digit = num % 2;
      current.push_back((digit == 0) ? '1' : '0');
      num = (num >> 1);
    }
    reverse(current.begin(), current.end());
    int res = 0;
    int weight = 1;
    for (int i = current.size() - 1; i >= 0; i--) {
      int currentCharacter = current[i];
      if (currentCharacter == '1') {
        res += weight;
      }
      weight = (weight << 1);
    }
    return res;
  }
};

int main() {
  Solution solve;
  int res = solve.findComplement(1);
  return 0;
}