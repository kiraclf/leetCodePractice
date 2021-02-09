#include <vector>
using namespace std;
class Solution {
 public:
  bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
    int row = 0, colu = matrix[0].size() - 1;
    while ( row >= 0 && row < matrix.size() && colu >= 0 && colu < matrix[0].size()) {
      if ( matrix[row][colu] == target) {
        return true;
      }
      if (matrix[row][colu] > target) {
        row--;
      } else {
        colu++;
      }
    }
    return false;
  }
};