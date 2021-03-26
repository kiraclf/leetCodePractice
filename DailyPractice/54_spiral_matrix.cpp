#include <vector>
using namespace std;
/*
包含第一个元素,不包含最后一个元素
*/

class Solution {
 public:
  vector<int> spiralOrder(vector<vector<int>>& matrix) {
    vector<int> res;
    int columnSize = matrix[0].size();
    int rowSize = matrix.size();
    int totalSize = columnSize * rowSize;
    int depth = 0;
    bool odd = !(matrix.size() % 2 == 0);
    if (rowSize == 1) {
      return matrix[0];
    }
    if (columnSize == 1) {
      for (int row = 0; row < rowSize; row++) {
        res.push_back(matrix[row][0]);
      }
      return res;
    }
    while (res.size() < totalSize) {
      int row = depth;
      int column = depth;
      if (odd && row == rowSize / 2) {
        while (column <= columnSize - depth - 1) {
          res.push_back(matrix[row][column]);
          column++;
        }
        continue;
      }
      // right
      while (column < columnSize - depth - 1) {
        res.push_back(matrix[row][column]);
        column++;
      }
      // bottom
      while (row < rowSize - depth - 1) {
        res.push_back(matrix[row][column]);
        row++;
      }
      // left
      while (column > depth) {
        res.push_back(matrix[row][column]);
        column--;
      }
      // top
      while (row > depth) {
        res.push_back(matrix[row][column]);
        row--;
      }
      depth++;
    }
    if (res.size() > columnSize * rowSize) {
      res.pop_back();
    } 
    return res;
  }
};

int main() {
  vector<vector<int>> test = {{1,2,3},{4,5,6}};
  Solution solve;
  vector<int> res = solve.spiralOrder(test);
  return 0;
}