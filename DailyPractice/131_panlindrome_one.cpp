/*
--- 题目描述 ---
给你一个字符串 s，请你将 s 分割成一些子串
使每个子串都是 回文串 -> 返回 s 所有可能的分割方案。
回文串 是正着读和反着读都一样的字符串。
--- 思路 ---
木有思路
--- 官方题解 ---
1. 使用 dfs 在每个可能分割的位置进行深度优先搜索
  * 在判断是否是回文字符串时,可以使用 dp 进行优化
  * f(i,j) 表示 s(i, j)是否为回文字符
  * f(i, j) = f(i+1,j-1) && (s[i] == s[j])
*/
#include <vector>
#include <string>
using namespace std;
class Solution {
 public:
  vector<vector<string>> partition(string s) {
    vector<vector<string>> ans;
    vector<string> current;
    dfs(0, current, s, ans);
    return ans;
  }

  void dfs(int index, vector<string> &current, string s, vector<vector<string>> &result) {
    int size = s.size();
    if (index == size) {
      result.push_back(current);
      return;
    }
    for (int i = index; i < size; i++) {
      string subString = s.substr(index, i - index + 1);
      if (stringReverseValidate(subString)) {
        current.push_back(subString);
        dfs(i + 1, current, s, result);
        current.pop_back();
      }
    }
  }

  bool stringReverseValidate(string s) {
    int size = s.length();
    if (size == 0) {
      return false;
    }
    int start = 0;
    int end = size - 1;
    while (start < end) {
      if (s[start] != s[end]) {
        return false;
      }
      start++;
      end--;
    }
    return true;
  }
};

int main() {
  Solution solve;
  vector<vector<string>> result = solve.partition("aab");
  return 0;
}