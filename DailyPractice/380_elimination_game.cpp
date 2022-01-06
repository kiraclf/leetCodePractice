class Solution {
 public:
  int lastRemaining(int n) {
    if (n == 1) {
      return 1;
    }
    int start = 1;
    int end = n;
    int totalSize = n;
    int leftToRight = true;
    int step = 1;
    while (totalSize != 1) {
      if (leftToRight) {
        start += step;
        if (totalSize % 2 != 0) {
          end -= step;
        }
      } else {
        end -= step;
        if (totalSize % 2 != 0) {
          start += step;
        }
      }
      int deleteCount = totalSize / 2;
      if (totalSize % 2 != 0) {
        deleteCount += 1;
      }
      totalSize -= deleteCount;
      leftToRight = !leftToRight;
      step *= 2;
    }
    return leftToRight ? start : end;
  }
};

int main() {
  Solution solve;
  int res = solve.lastRemaining(30);
  return 0;
}