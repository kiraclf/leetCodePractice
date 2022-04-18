class Solution {
 public:
  int countNumbersWithUniqueDigits(int n) {
    if (n <= 1) {
      return n == 0 ? 1 : 10;
    }
    int before = 10;
    int bbefore = 1;
    int ans = 0;
    // dp[n] = dp[n-1] + (dp[n-1] - dp[n-2]) * (9 - (n - 1))
    for (int i = 2; i <= n; i++) {
      int current = before + (before - bbefore) * (11 - i);
      bbefore = before;
      before = current;
    }
    return before;
  }
};