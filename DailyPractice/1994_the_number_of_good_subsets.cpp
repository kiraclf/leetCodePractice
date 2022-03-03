#include <unordered_set>
#include <vector>
using namespace std;
static const int mod = 1000000007;
class Solution {
 public:
  int numberOfGoodSubsets(vector<int>& nums) {
    long long res = 0;
    vector<int> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
    vector<long long> dp(1024, 0);
    // dp init
    dp[0] = 1;
    // get number count
    vector<int> count(31, 0);
    for (auto number : nums) {
      count[number]++;
    }
    // check everty digit
    for (int num = 2; num <= 30; num++) {
      // no current number or sqaure number, skip
      if (count[num] == 0 || num % 4 == 0 || num % 9 == 0 || num % 25 == 0) {
        continue;
      }
      // check current number's mask
      int maskForNum = 0;
      for (int i = 0; i < 10; i++) {
        if (num % primes[i] == 0) {
          maskForNum |= (1 << i);
        }
      }
      // check each state
      for (int state = 0; state < 1024; state++) {
        if ((maskForNum & state) > 0) {
          // duplicate prime
          continue;
        }
        dp[maskForNum | state] =
            (dp[maskForNum | state] + count[num] * dp[state]) % mod;
      }
    }
    for (int i = 1; i < 1024; i++) {
      res = (res + dp[i]) % mod;
    }
    for (int i = 0; i < count[1]; i++) {
      res = (res * 2) % mod;
    }
    return (int)res;
  }
};