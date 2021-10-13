#include <vector>
#include <string>
using namespace std;
class Solution {
 public:
  int minDistance(string word1, string word2) {
    // dp[a,b] 表示以a,b结尾的最长大小
    // dp[0,0] = word1[0] == word2[0]? 1 : 0
    // dp[x,y] = word1[x] == word2[y] ? max(dp[x-1][y], dp[x][y-1]) + 1 : max(dp[x-1][y], dp[x][y-1])
    vector<vector<int>> dp(word1.size(), vector<int>(word2.size(), 0));
    dp[0][0] = word1[0] == word2[0] ? 1 : 0;
    for (int i = 0; i < word1.size(); i++) {
      dp[i][0] = word1[i] == word2[0] ? 1 : dp[i-1][0];
    }
    for (int i = 0; i < word2.size(); i++) {
      dp[0][i] = word1[0] == word2[i] ? 1 : dp[0][i-1];
    }
   
    for (int i = 1; i < word1.size(); i++) {
      for (int j = 1; j < word2.size(); j++) {
        dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
        if (word1[i] == word2[j]) {
          dp[i][j] = dp[i-1][j-1] + 1;
        }
      }
    }
    int maxCount = dp[word1.size() -1][word2.size() - 1];
    return word2.size() + word1.size() - 2 * maxCount;
  }
};

int main() {
  Solution solve;
  string test1 = "a";
  string test2 = "a";
  int result = solve.minDistance(test1, test2);
  return 0;
}