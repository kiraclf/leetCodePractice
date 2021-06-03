class Solution {
 public:
  bool isPowerOfFour(int n) {
    // 1 case handled.
    if ( n == 1) {
      return true;
    }
    // negative is impossible.
    if ( n < 0) {
      return false;
    }
    // mask
    int mask = 4;
    while ( mask <= n) {
      if ( (n ^ mask) != 0) {
        if (mask == (1 << 30)) {
          break;
        }
        mask = mask << 2;
      } else {
        return true;
      } 
    }
    return false;
  }
};

int main() {
  Solution solve;
  bool result = solve.isPowerOfFour(5);
  return 0;
}