using namespace std;
class Solution {
 public:
  int addDigits(int num) {}

  int addDigitsRescursive(int num) {
    if (num < 10) {
      return num;
    }
    int digitSum = 0;
    while (num != 0) {
      digitSum += (num % 10);
      num = num / 10;
    }
    return addDigitsRescursive(digitSum);
  }
};