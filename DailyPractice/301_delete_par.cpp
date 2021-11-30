#include <string>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
 public:
  // 只能使用 dfs 进行爆搜
  vector<string> removeInvalidParentheses(string s) {}

 private:
  unordered_set<string> cache;
  int stringSize;
};