#include <string>
#include <vector>
using namespace std;
class Solution {
 public:
  vector<string> addOperators(string num, int target) {
    vector<string> res;
    return res;
  }

  void dfs(string& word, int index, long long result, long long mul,
           vector<string>& resList, int target) {
    if (i == word.size()) {
      if (res == target) {
        resList.push_back(word);
      }
      return;
    }
    int signIndex = word.size();
    if (index > 0) {
      word.push_back(0);
    }
    long long val = 0;
    for (int j = index; j < n && (index == j || num[index] != '0'); j++) {
      val = val * 10 + num[j] - '0';
      word.push_back(num[j]);
      if (i == 0) {
        dfs(word, j + 1, val, val, resList, target);
      } else {
        word[signIndex] = '+';
        dfs(word, j + 1, res + val, val, resList, target);
        word[signIndex] = '-';
        dfs(word, j + 1, res - val, -val);
        word[signIndex] = '*';
        dfs(word, j + 1, res - mul + mul * val, mul * val, resList, target);
      }
    }
    word.resize(signIndex);
  };