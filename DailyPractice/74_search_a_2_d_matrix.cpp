#include <vector>
using namespace std;
/*
直接使用二分法进行搜索
*/
class Solution {
 public:
  bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int totalCount = matrix.size() * matrix[0].size();
    // binary search
    int left = 0;
    int right = totalCount - 1;
    while (left <= right) {
      int mid = (left + right) / 2;
      int midValue = getMatrixValue(matrix, mid);
      if (target == midValue) {
        return true;
      } else if (target > midValue) {
        left = mid + 1;
      } else {
        right = mid - 1;
      }
    }
    return false;
  }

  int getMatrixValue(vector<vector<int>>& matrix, int indexNumber) {
    int columnCount = matrix[0].size();
    int rowIndex = indexNumber / columnCount;
    int columnIndex = indexNumber - rowIndex * columnCount;
    return matrix[rowIndex][columnIndex];
  }
};