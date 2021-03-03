#include <vector>
using namespace std;
class Solution {
 public:
  vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
    int rowSize = nums.size();
    if (rowSize == 0) {
      // input illegal
      return nums;
    }
    int columSize = nums[0].size();
    int totalCount = rowSize * columSize;
    if ( totalCount != r * c) {
      // illegal
      return nums;
    }
    vector<vector<int>> ans(r, vector<int>(c));
    for (int row = 0; row < r; row++) {
      for (int col = 0; col < c; col++) {
        int index = row * c + col;
        int rowIndex = index / columSize;
        int columIndex = index - rowIndex * columSize;
        ans[row][col] = nums[rowIndex][columIndex];
      }
    }
    return ans;
  }
};