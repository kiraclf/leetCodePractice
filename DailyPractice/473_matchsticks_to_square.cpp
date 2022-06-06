#include <vector>
using namespace std;
class Solution {
 private:
  vector<int> sticks;

 public:
  bool makesquare(vector<int>& matchsticks) {
    int sum = 0;
    this->sticks = matchsticks;
    for (auto stick : matchsticks) {
      sum += stick;
    }

    if (sum % 4 != 0) {
      return false;
    }
    int line = sum / 4;
    return dfs(0, 0, 0, sum, 0);
  }

  bool dfs(int currentSize, int occuipied, int currentSum, int targetSum,
           int selectIndex) {
    if (((occuipied >> selectIndex) & 1) == true) {
      // used.
      return false;
    }
    // update occuipied
    occuipied = (occuipied | (1 << selectIndex));
    if (currentSize + sticks[selectIndex] > (targetSum / 4)) {
      return false;
    }
    if (currentSize + sticks[selectIndex] == (targetSum / 4)) {
      currentSize = 0;
      currentSum += sticks[selectIndex];
      if (currentSum == targetSum) {
        return true;
      } else {
        // drill down.
        for (int i = 0; i < sticks.size(); i++) {
          bool res = dfs(currentSize, occuipied, currentSum, targetSum, i);
          if (res) {
            return res;
          }
        }
        return false;
      }
    } else {
      currentSize += sticks[selectIndex];
      currentSum += sticks[selectIndex];
      // drill down.
      for (int i = 0; i < sticks.size(); i++) {
        if (((occuipied >> i) & 1) == 1) {
          continue;
        }
        bool res = dfs(currentSize, occuipied, currentSum, targetSum, i);
        if (res) {
          return res;
        }
      }
      return false;
    }
  }
};

int main() {
  Solution solve;
  vector<int> test = {3, 3, 3, 3, 4};
  auto res = solve.makesquare(test);
  return 0;
}