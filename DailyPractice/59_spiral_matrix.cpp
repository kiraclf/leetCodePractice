#include <vector>
using namespace std;
class Solution {
 public:
  vector<vector<int>> generateMatrix(int n) {
    vector<vector<int>> res(n, vector<int>(n, 0));
    int step = 0;
    int value = 1;
    while (value <= n * n) {
      int row = step;
      int column = step;
      // go right
      while (column < n - step) {
        res[row][column] = value;
        value++;
        column++;
      }
      column--;
      // go down
      row++;
      while (row < n - step) {
        res[row][column] = value;
        value++;
        row++;
      }
      row--;
      // go left
      column--;
      if (column < 0 || res[row][column] != 0) {
        // can't go left
        step++;
        break;
      }
      while (column >= step) {
        res[row][column] = value;
        value++;
        column--;
      }
      column++;
      // go top
      row--;
      while (row > step) {
        res[row][column] = value;
        value++;
        row--;
      }
      step++;
    }
    return res;
  }
};

int main() {
  Solution solve;
  vector<vector<int>> res = solve.generateMatrix(6);
  return 0;
}