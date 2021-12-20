#include <vector>
using namespace std;
class Solution {
  constexpr static int MOD = 1337;

 public:
  /// 快速幂
  int pow(int a, int b) {
    int ans = 1;
    while (b != 0) {
      if (b & 1) {
        ans = ans * a % MOD;
      }
      a = (long)a * a % MOD;
      b >>= 1;
    }
    return ans;
  }
  int superPow(int a, vector<int>& b) {
    int ans = pow(a, b[0]);
    for (int i = 1; i < b.size(); i++) {
      ans = pow(ans, 10) * pow(a, b[i]) % MOD;
    }
    return ans;
  }
};