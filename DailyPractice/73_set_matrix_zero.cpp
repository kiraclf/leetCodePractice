#include <vector>
using namespace std;
/*
核心在于如何存储 0 的位置
*/
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        
    }

    // 使用 row 和 col 来保存0的位置
    // 时间复杂度 O(mn） 空间复杂度 O(m+n)
    void setZeros1(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> row(m), col(n);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!matrix[i][j]) {
                    row[i] = col[j] = true;
                }
            }
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (row[i] || col[j]) {
                    matrix[i][j] = 0;
                }
            }
        }
    }

    // 使用数组的第一行和第一列代替方法中的两个标记数组
    // 使用额外两个变量记录第一行第一列是否包含0
    void setZeroes2(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int flag_col0 = false, flag_row0 = false;
        for (int i = 0; i < m; i++) {
            if (!matrix[i][0]) {
                flag_col0 = true;
            }
        }
        for (int j = 0; j < n; j++) {
            if (!matrix[0][j]) {
                flag_row0 = true;
            }
        }
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (!matrix[i][j]) {
                    matrix[i][0] = matrix[0][j] = 0;
                }
            }
        }
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (!matrix[i][0] || !matrix[0][j]) {
                    matrix[i][j] = 0;
                }
            }
        }
        if (flag_col0) {
            for (int i = 0; i < m; i++) {
                matrix[i][0] = 0;
            }
        }
        if (flag_row0) {
            for (int j = 0; j < n; j++) {
                matrix[0][j] = 0;
            }
        }
    }
};