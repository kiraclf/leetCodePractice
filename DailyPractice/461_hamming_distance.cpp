class Solution {
 public:
  int hammingDistance(int x, int y) {
    int result = 0;
    for (int i = 0; i < 32; i++) {
      int mask = 1 << i;
      if (mask <= x || mask <= y) {
        if ((x & mask) == (y & mask)) {
          result++;
        }
      } else {
        break;
      }
    }
    return result;
  }
};

int main() {
  Solution solve;
  int result = solve.hammingDistance(1,4);
  return 0;
}