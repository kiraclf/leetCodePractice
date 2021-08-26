#include <vector>
using namespace std;
class Solution {
 public:
  int getMaximumGenerated(int n) {
    if ( n == 0) {
      return 0;
    }
    vector<int> numbers(n + 1, 0);
    numbers[0] = 0;
    numbers[1] = 1;
    int maxValue = 1;
    int index = 2;
    while (index < numbers.size()) {
      if (index % 2 == 0) {
        numbers[index] = numbers[index/2];
      } else {
        int evenNumber = (index - 1) / 2;
        numbers[index] = numbers[evenNumber] + numbers[evenNumber + 1];
        maxValue = max(maxValue, numbers[index]);
      }
      index++;
    }
    return maxValue;
  }
};

int main() {
  Solution solve;
  int result = solve.getMaximumGenerated(3);
  return 0;
}