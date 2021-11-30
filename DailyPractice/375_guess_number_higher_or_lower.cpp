#include <vector>
using namespace std;
class Solution {
 public:
  int getMoneyAmount(int n) {
    int maxMoney = INT_MAX;
    dfs(1, n, 0, maxMoney);
    return maxMoney;
  }

  void dfs(int start, int end, int currentCost, int &maxMoney) {
    if (start == end) {
      maxMoney = min(currentCost, maxMoney);
      return;
    }
    for (int i = start; i <= end; i++) {
      currentCost += i;
      if (i > start) {
        dfs(start, i - 1, currentCost, maxMoney);
      }
      if (i < end) {
        dfs(i + 1, end, currentCost, maxMoney);
      }
    }
  }
};

int main() {
  Solution solve;
  int res = solve.getMoneyAmount(10);
  return 0;
}