#include <string>
#include <unordered_map>
#include <vector>
using namespace std;
static const int divider = 1000000007;
class Solution {
 public:
  int countVowelPermutation(int n) {
    if (n == 0) {
      return 0;
    }
    if (n == 1) {
      return 5;
    }
    unordered_map<int, vector<int>> charMap{{0, {1}},           // a
                                            {1, {0, 2}},        // e
                                            {2, {0, 1, 3, 4}},  // i
                                            {3, {2, 4}},        // o
                                            {4, {0}}};          // u
    // dp[length][char] 表示长度为length 以 char 结尾的个数
    // Create DP
    vector<int> lengthVec(5, 0);
    vector<vector<int>> dp(n + 1, lengthVec);
    // DP init
    for (int i = 0; i < 5; i++) {
      dp[1][i] = 1;
    }
    // DP process
    for (int i = 2; i < dp.size(); i++) {
      for (int j = 0; j < 5; j++) {
        vector<int> possibleTranser = charMap[j];
        for (auto next : possibleTranser) {
          dp[i][next] += (dp[i - 1][j] % divider);
          dp[i][next] = dp[i][next] % divider;
        }
      }
    }
    // DP getResult
    int res = 0;
    for (int i = 0; i < 5; i++) {
      res += (dp[n][i] % divider);
      res = (res % divider);
    }
    return res;
  }
};

int main() {
  Solution solve;
  int count = solve.countVowelPermutation(5);
  return 0;
}