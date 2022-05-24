#include <algorithm>
class Solution {
 public:
  int findKthNumber(int m, int n, int k) {
    int left = 1, right = m * n;
    int ans = 0;
    while (left <= right) {
      if (left == right) {
      }
      int x = left + (right - left) / 2;
      int count = 0;
      for (int i = 1; i <= m; i++) {
        count += std::min(x / i, n);
      }
      if (count == k) {
        return x;
      } else if (count > k) {
        right = x - 1;
        ans = right;
      } else {
        left = x + 1;
        ans = left;
      }
    }
    return ans;
  }
};

int main() {
  Solution solve;
  int res = solve.findKthNumber(45, 12, 471);
  return 0;
}