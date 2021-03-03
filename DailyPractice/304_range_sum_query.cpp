#include <vector>
using namespace std;
/*
--- 题目 ---
给定一个二维矩阵，计算其子矩形范围内元素的总和，该子矩阵的左上角为 (row1, col1)
，右下角为 (row2, col2)。
上图子矩阵左上角 (row1, col1) = (2, 1) ，右下角(row2, col2) = (4,
3)，该子矩形内元素的总和为 8。
--- 思路 ---
1. 每行记录累加和,然后每列进行叠加
--- 官方题解 ---
还是利用前缀和的思想,不过在计算时 f(i, j) 为以 [i, j]为右下角的和
f(i, j) = f(i - 1, j) + f(i, j - 1) - f(i - 1, j - 1) + value(i-1, j-1)
*/

class NumMatrix {
 public:
  NumMatrix(vector<vector<int>>& matrix) {
    numMatrix = vector<vector<int>>();
    for (int i = 0; i < matrix.size(); i++) {
      vector<int> currentRow;
      int sum = 0;
      for (int j = 0; j < matrix[i].size(); j++) {
        sum += matrix[i][j];
        currentRow.push_back(sum);
      }
      numMatrix.push_back(currentRow);
    }
  }

  int sumRegion(int row1, int col1, int row2, int col2) {
    int sum = 0;
    for (int row = row1; row <= row2; row++) {
      if (col1 - 1 >= 0) {
        sum += numMatrix[row][col2] - numMatrix[row][col1 - 1];
      } else {
        sum += numMatrix[row][col2];
      }
    }
    return sum;
  }
private:
  vector<vector<int>> numMatrix;
};