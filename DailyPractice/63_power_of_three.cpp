using namespace std;
class Solution {
 public:
  bool isPowerOfThree(int n) {
    if (n == 0) {
      return false;
    }
    while (n != 1) {
      int remain = n % 3;
      if (remain != 0) {
        return false;
      }
      n = n / 3;
    }
    return true;
  }
};