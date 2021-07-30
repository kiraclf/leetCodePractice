#include <string>
using namespace std;
class Solution {
 public:
  int titleToNumber(string columnTitle) {
    int number = 0;
    for (int i = 0; i < columnTitle.size(); i++) {
      int currentValue = columnTitle[i] - 'A' + 1;
      number = number * 26 + currentValue;
    }
    return number;
  }
};

int main() {
  Solution solve;
  string test = "AB";
  int column = solve.titleToNumber(test);
  return 0;
}