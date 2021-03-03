#include <vector>
using namespace std;
/*
给你一个 m x n 的矩阵 matrix 。
如果这个矩阵是托普利茨矩阵，返回 true
否则，返回 false
如果矩阵上每一条由左上到右下的对角线上的元素都相同，那么这个矩阵是 托普利茨矩阵
*/
class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
      int rowCount = matrix.size();
      int columnCount = rowCount >= 1 ? matrix[0].size() : 0;
      for (int column = 0; column < columnCount; column++) {
        int matrixValue = 0;
        int currentColumn = column;
        for (int row = 0; row < rowCount && currentColumn < columnCount; row++) {
          if (row == 0) {
            matrixValue = matrix[row][currentColumn];
          } else {
            if (matrixValue != matrix[row][currentColumn]) {
              return false;
            }
          }
          currentColumn++;
        }
      }
      for (int row = 0; row < rowCount; row++) {
        int matrixValue = 0;
        int currentRow = row;
        for (int column = 0; column < columnCount && currentRow < rowCount; column++) {
          if (column == 0) {
            matrixValue = matrix[currentRow][column];
          } else {
            if (matrixValue != matrix[currentRow][column]) {
              return false;
            }
          }
          currentRow++;
        }
      }
      return true;
    }

    bool isToeplitzMatrixOfficial(vector<vector<int>>& matrix) {
      int rowCount = matrix.size();
      int columnCount = rowCount >= 1 ? matrix[0].size() : 0;
      for (int row = 1; row < rowCount; row++) {
        for (int colum = 1; colum < columnCount; colum++) {
          if (matrix[row][colum] != matrix[row-1][colum-1]) {
            return false;
          }
        }
      }
      return true;
    }
};

int main() {
  Solution solution;
  vector<vector<int>> test = {{1,2,3,4}, {5,1,2,3}, {9,5,1,2}};
  vector<vector<int>> test2 = {{1,2}, {2,2}};
  bool result = solution.isToeplitzMatrix(test);
  bool result2 = solution.isToeplitzMatrix(test2);
  return 0;
}