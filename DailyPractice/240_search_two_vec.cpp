#include <vector>
using namespace std;
class Solution {
 public:
  bool searchMatrix(vector<vector<int>>& matrix, int target) {
    for (int row = 0; row < matrix.size(); row++) {
      int rowMin = matrix[row][0];
      int rowMax = matrix[row][matrix[row].size() - 1];
      if (target < rowMin || target > rowMax) {
        continue;
      }
      int start = 0;
      int end = matrix[row].size() - 1;
      while (start <= end) {
        int mid = start + (end - start) / 2;
        if (matrix[row][mid] > target) {
          end = mid - 1;
        } else if (matrix[row][mid] < target) {
          start = mid + 1;
        } else {
          return true;
        }
      }
    }
    return false;
  }
};