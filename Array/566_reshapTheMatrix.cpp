#include <vector>
using namespace std;

/**
 * You're given a matrix represented by a two-dimensional array, 
 * and two positive integers r and c representing the row number and column number of the wanted reshaped matrix, respectively.
 * The reshaped matrix need to be filled with all the elements of the original matrix in the same row-traversing order as they were.
 * If the 'reshape' operation with given parameters is possible and legal, output the new reshaped matrix; Otherwise, output the original matrix.
*/

class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        // check if vaildate
        if (getMatrixSize(nums) != r * c) {
            // Invalidate
            return nums;
        }
        // ans init
        vector<int> column(c);
        vector<vector<int>> ans(r, column);
        // transform ans matrix
        for (int rowIndex = 0; rowIndex < nums.size(); rowIndex++) {
            for (int columnIndex = 0; columnIndex < nums[rowIndex].size(); columnIndex++) {
                int arrayIndex = rowIndex * nums[rowIndex].size() + columnIndex;
                int ansRowIndex = arrayIndex / c;
                int ansColumnIndex = arrayIndex % c;
                ans[ansRowIndex][ansColumnIndex] = nums[rowIndex][columnIndex];
            }
        }
        return ans;
    }

    int getMatrixSize(vector<vector<int>>& matrix) {
        if ( matrix.size() == 0) {
            return 0;
        }
        return matrix[0].size() * matrix.size();
    }
};