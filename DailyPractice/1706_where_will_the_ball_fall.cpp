#include <vector>
using namespace std;
class Solution {
 public:
  vector<int> findBall(vector<vector<int>>& grid) {
    // init ans.
    vector<int> ans(grid[0].size(), 0);
    for (int i = 0; i < ans.size(); i++) {
      ans[i] = i;
    }
    // fall through
    int currentLevel = 0;
    while (currentLevel <= grid.size() - 1) {
      for (int i = 0; i < ans.size(); i++) {
        int currentPosistion = ans[i];
        if (currentPosistion == -1) {
          continue;
        }
        int currentLine = grid[currentLevel][currentPosistion];
        if (currentLine == 1) {
          // right
          if (currentPosistion + 1 >= grid[0].size()) {
            // out of range
            ans[i] = -1;
          } else if (grid[currentLevel][currentPosistion + 1] == -1) {
            // jam
            ans[i] = -1;
          } else {
            ans[i] = currentPosistion + 1;
          }
        } else {
          // left
          if (currentPosistion - 1 < 0) {
            // out of range
            ans[i] = -1;
          } else if (grid[currentLevel][currentPosistion - 1] == 1) {
            // jam
            ans[i] = -1;
          } else {
            ans[i] = currentPosistion - 1;
          }
        }
      }
      currentLevel++;
    }
    // return ans
    return ans;
  }
};

int main() {
  Solution solve;
  vector<vector<int>> board = {{-1}};
  vector<int> ans = solve.findBall(board);
  return 0;
}