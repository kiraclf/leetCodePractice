#include <vector>
using namespace std;
class Solution {
 public:
  vector<int> lexicalOrder(int n) {
    vector<int> result;
    for (int i = 1; i <= min(9, n); i++) {
      dfs(result, i, n);
    }
    return result;
  }

  void dfs(vector<int>& result, int before, int maxValue) {
    if (before > maxValue) {
      return;
    }
    result.push_back(before);
    for (int i = 0; i <= 9; i++) {
      dfs(result, before * 10 + i, maxValue);
    }
  }
};

int main() {
  Solution solve;
  vector<int> res = solve.lexicalOrder(2);
  return 0;
}