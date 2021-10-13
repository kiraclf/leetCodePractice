#include <string>
#include <vector>
using namespace std;
int mask = 1000000007;
class Solution {
 public:
 /*
 dp[i][j]  i -- 0...字符串的长度, j...表示字符串的值(0...9) 值为当前值的方法的数目
 dp[i][j] = 
 */
  int numDecodings(string s) {
    // exception
    if (s.size() == 0) {
      return 0;
    }
    // dp[i][j]
    vector<vector<int>> dp(s.size(), vector<int>(10, 0));
    // 初始化dp
    if (s[0] == '*') {
      for (int j = 1; j <= 9; j++) {
        dp[0][j] = 1;
      }
    } else {
      int number = s[0] - '0';
      if (number == 0) {
        dp[0][number] = 0;
      } else {
        dp[0][number] = 1;
      }
    }
    // 生成 dp
    for (int i = 1; i < s.size(); i++) {
      char character = s[i];
      if (character == '*') {
        // 可以取值为 1..<9
        for (int index = 1; index <=9; index++) {
          if (index == 0) {
            // 只能取之前的值
            if (s[i - 1] == '*') {
              dp[i][index] =
                  (i - 2 >= 0) ? ((getTotal(i - 2, dp) * 2) % mask) : 2;
            } else if (s[i - 1] == '1' || s[i - 1] == '2') {
              dp[i][index] = (i - 2 >= 0) ? getTotal(i - 2, dp) : 1;
            }
          } else if (index <= 6) {
            // 可以取当前位的值,可以取与之前组合的值
            // 与之前的组合
            if (s[i - 1] == '*') {
              dp[i][index] =
                  (i - 2 >= 0) ? ((getTotal(i - 2, dp) * 2) % mask) : 2;
            } else if (s[i - 1] == '1' || s[i - 1] == '2') {
              dp[i][index] = (i - 2 >= 0) ? getTotal(i - 2, dp) : 1;
            }
            // 直接使用当前
            dp[i][index] += getTotal(i - 1, dp);
          } else {
            // 与之前组成
            if (s[i - 1] == '*' || s[i - 1] == '1') {
              dp[i][index] += (i - 2 >= 0) ? ((getTotal(i - 2, dp)) % mask) : 1;
            }
            // 自身组成
            dp[i][index] += getTotal(i - 1, dp);
          }
        }
      } else {
        int index = character - '0';
        if (index == 0) {
          // 只能取之前的值
          if (s[i-1] == '*') {
            dp[i][index] = (i-2 >= 0) ? ((getTotal(i-2, dp) * 2) % mask) : 2; 
          } else if (s[i - 1] == '1' || s[i - 1] == '2') {
            dp[i][index] = (i-2 >= 0) ? getTotal(i-2, dp) : 1;
          }
        } else if (index <= 6) {
          // 可以取当前位的值,可以取与之前组合的值
          // 与之前的组合
          if (s[i-1] == '*') {
            dp[i][index] = (i-2 >= 0) ? ((getTotal(i-2, dp) * 2) % mask) : 2;
          } else  if (s[i-1] == '1' || s[i-1] == '2'){
            dp[i][index] = (i - 2 >= 0) ? getTotal(i - 2, dp) : 1;
          }
          // 直接使用当前
          dp[i][index] += getTotal(i-1, dp);
        } else {
          // 与之前组成
          if (s[i-1] == '*' || s[i-1] == '1') {
            dp[i][index] +=
                (i - 2 >= 0) ? ((getTotal(i - 2, dp)) % mask) : 1;
          }
          // 自身组成
          dp[i][index] += getTotal(i-1, dp);
        }
      }
    }
    return getTotal(s.size() - 1, dp);
  }

  int getTotal(int index, vector<vector<int>>& dp) {
    int sum = 0;
    for (int i = 0; i < dp[index].size(); i++) {
      sum += dp[index][i];
      sum = sum % mask;
    }
    return sum;
  }
};

int main() {
  Solution solve;
  string test = "***********";
  int count = solve.numDecodings(test);
  return 0;
}