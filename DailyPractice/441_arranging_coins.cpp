class Solution {
 public:
  int arrangeCoins(int n) {
    int floor = 1;
    while ( n > 0) {
      n -= floor;
      if ( n <= 0) {
        return n == 0 ? floor : floor - 1;
      }
      floor++;
    }
    return floor;
  }
};

int main() {
  Solution solve;
  int result = solve.arrangeCoins(3);
  return 0;
}