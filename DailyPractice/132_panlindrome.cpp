/*
--- 题目描述 ---
给你一个字符串 s，请你将 s 分割成一些子串，使每个子串都是回文。
返回符合要求的 最少分割次数 。
*/
#include <string>
#include <vector>
using namespace std;
class Solution {
   public:
    int minCut(string s) {
      int n = s.size();
      vector<vector<int>> st(n, vector<int>(n));
      for (int j = 0; j < n; j++) {
        for (int i = j; i >= 0; i--) {
          if (i == j)
            st[i][j] = true;
          else if (j - i + 1 == 2)
            st[i][j] = (s[i] == s[j]);
          else
            st[i][j] = (s[i] == s[j]) && st[i + 1][j - 1];
        }
      }
      vector<int> f(n);
      for (int j = 1; j < n; j++) {
        if (st[0][j])
          f[j] = 0;
        else {
          f[j] = f[j - 1] + 1;
          for (int i = 1; i < j; i++) {
            if (st[i][j]) f[j] = min(f[j], f[i - 1] + 1);
          }
        }
      }
      return f[n - 1];
    }
  };