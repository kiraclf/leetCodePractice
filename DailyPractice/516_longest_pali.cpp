#include <string>
#include <vector>
using namespace std;
class Solution {
 public:
  int longestPalindromeSubseq(string s) {
    int size = s.size();
    if (size <= 1) {
      return size;
    }
    // 产生 reversed
    string sReversed = "";
    for (int i = s.size() - 1; i >= 0; i--) {
      sReversed += s[i];
    }
    // dp
    vector<vector<int>> dpArr(s.size(), vector<int>(s.size(), 0));
    // 初始化 dp
    dpArr[0][0] = (s[0] == sReversed[0]) ? 1 : 0;
    for (int i = 1; i < dpArr.size(); i++) {
      dpArr[i][0] = (s[i] == sReversed[0]) ? 1 : dpArr[i - 1][0];
    }
    for (int i = 1; i < dpArr[0].size(); i++) {
      dpArr[0][i] = (s[0] == sReversed[i]) ? 1 : dpArr[0][i-1];
    }
    for (int i = 1; i < dpArr.size(); i++) {
      for (int j = 1; j < dpArr[i].size(); j++) {
        bool charEqual = s[i] == sReversed[j];
        if (charEqual) {
          dpArr[i][j] = max(dpArr[i-1][j], dpArr[i][j-1]);
          dpArr[i][j] = max(dpArr[i - 1][j - 1] + 1, dpArr[i][j]);
        } else {
          dpArr[i][j] = max(dpArr[i][j-1], dpArr[i-1][j]);
        }
      }
    }
    int result = dpArr[size-1][size-1];
    return result;
  }
};

int main() {
  Solution solve;
  string test = "bbbab";
  int count = solve.longestPalindromeSubseq(test);
  return 0; 
}