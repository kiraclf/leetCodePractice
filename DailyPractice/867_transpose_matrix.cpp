#include <vector>
using namespace std;
class Solution {
 public:
  vector<vector<int>> transpose(vector<vector<int>>& matrix) {
    // exception
    int rowSize = matrix.size();
    if (rowSize == 0) {
      return matrix;
    }
    int columnSize = matrix[0].size();
    // transpose
    vector<vector<int>> targetMatrix(columnSize, vector<int>(rowSize, 0));
    for (int row = 0; row < targetMatrix.size(); row++) {
      for (int column = 0; column < targetMatrix[0].size(); column++) {
        targetMatrix[row][column] = matrix[column][row];
      }
    }
    return targetMatrix;
  }
};