#include <string>
#include <vector>
using namespace std;
class Solution {
 private:
  int catJump;
  int mouseJump;
  vector<string> grid;
  vector<vector<vector<int>>> status;
  int rowCount;
  int columnCount;

 public:
  bool canMouseWin(vector<string>& grid, int catJump, int mouseJump) {
    this->catJump = catJump;
    this->mouseJump = mouseJump;
    this->grid = grid;
    this->rowCount = grid.size();
    this->columnCount = grid[0].size();
    // [catPosistion][mousePosistion][turn]
    // -1: unknown, 0: mouse wins, 1: cat wins
    vector<int> turns(1000, -1);
    vector<vector<int>> mouseP(rowCount * columnCount, turns);
    this->status = vector<vector<vector<int>>>(rowCount * columnCount, mouseP);
    int catIndex = -1;
    int mouseIndex = -1;
    // init
    for (int row = 0; row < grid.size(); row++) {
      for (int column = 0; column < grid[row].size(); column++) {
        if (grid[row][column] == 'C') {
          catIndex = row * columnCount + column;
        } else if (grid[row][column] == 'M') {
          mouseIndex = row * columnCount + column;
        }
      }
    }
    return dfs(catIndex, mouseIndex, 0);
  }

  bool dfs(int cat, int mouse, int turn) {
    if (turn == 1000) {
      return false;
    }
    if (turn % 2 == 0) {
      // mouse turn

    } else {
      // cat turn
    }
  }
};