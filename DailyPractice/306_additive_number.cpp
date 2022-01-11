#include <string>
#include <vector>
using namespace std;
class Solution {
 public:
  bool isAdditiveNumber(string num) {
    int firstEndIndex = 0;
    for (int i = firstEndIndex; i < num.size() - 1; i++) {
      for (int j = i + 1; j < num.size(); j++) {
        long long firstNumber = getNumber(num, 0, i + 1);
        long long secondNumber = getNumber(num, i + 1, j - i);
        if (firstNumber == -1 || secondNumber == -1) {
          continue;
        }
        if (validate(secondNumber, firstNumber, j + 1, num, 2)) {
          return true;
        }
      }
    }
    return false;
  }

  long long getNumber(string num, int startIndex, int length) {
    long long number = 0;
    if (num[startIndex] == '0' && length > 1) {
      return -1;
    }
    for (int i = startIndex; i < startIndex + length; i++) {
      number = number * 10 + num[i] - '0';
    }
    return number;
  }

  bool validate(long long before, long long beforeBefore, int startIndex,
                string num, int totalNumber) {
    if (startIndex == num.size()) return totalNumber == 2 ? false : true;
    long long target = before + beforeBefore;
    int digitSize = 0;
    long long temp = target;
    while (target != 0) {
      target /= 10;
      digitSize++;
    }
    target = temp;
    if (startIndex + digitSize - 1 >= num.size()) {
      return false;
    }
    for (int i = startIndex + digitSize - 1; i >= startIndex; i--) {
      int number = (int)(num[i] - '0');
      if (number != (target % 10)) {
        return false;
      }
      target /= 10;
    }
    if (digitSize == 0) {
      digitSize++;
    }
    return validate(temp, before, startIndex + digitSize, num, totalNumber + 1);
  }
};

int main() {
  Solution solve;
  string test = "101020305080130210";
  bool result = solve.isAdditiveNumber(test);
  return 0;
}