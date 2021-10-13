class Solution {
 public:
  int getSum(int a, int b) {
    unsigned result = 0;
    bool upgrade = false;
    for (int i = 0; i < 32; i++) {
      unsigned mask = 1 << i;
      unsigned a_digit = (a & mask) >> i;
      unsigned b_digit = (b & mask) >> i;
      int sum_digit = 0;
      if (a_digit == 0 && b_digit == 0) {
        sum_digit = 0;
        if (upgrade) {
          sum_digit = 1;
          upgrade = false;
        }
      }
      if (a_digit == 1 && b_digit == 1) {
        sum_digit = 0;
        if (upgrade) {
          sum_digit = 1;
        }
        upgrade = true;
      }
      if (a_digit == 0 && b_digit == 1) {
        sum_digit = 1;
        if (upgrade) {
          sum_digit = 0;
          upgrade = true;
        }
      }
      if (a_digit == 1 && b_digit == 0) {
        sum_digit = 1;
        if (upgrade) {
          sum_digit = 0;
          upgrade = true;
        }
      }
      result = result | (sum_digit << i);
    }
    return result;
  }
};

int main() {
  Solution solve;
  int result = solve.getSum(-12,-8);
  return 0;
}