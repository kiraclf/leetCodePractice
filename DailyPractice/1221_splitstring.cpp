#include <string>
using namespace std;
class Solution {
 public:
  int balancedStringSplit(string s) {
    int count = 0;
    int current = 0;
    for (int i = 0; i < s.size(); i++) {
      if (s[i] == 'L') {
        current += 1;
      } else {
        current -= 1;
      }
      if (current == 0) {
        count++;
      }
    }
    return count;
  }
};

int main() {
  Solution solve;
  int result = solve.balancedStringSplit("LLLLRRRR");
  return 0;
}