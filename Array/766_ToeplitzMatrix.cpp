#include <vector>
using namespace std;

class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        // 异常判断
        if (matrix.size() == 0) return true;
        if (matrix[0].size() == 0) return true;
        // 遍历
        for (int i = 0; i < matrix.size(); i++) {
            int indexX = 0;
            int indexY = i;
            int value = matrix[indexY][indexX];
            while (indexX < matrix[0].size() && indexY < matrix.size()) {
                if (matrix[indexY][indexX] != value) {
                    return false;
                }
                indexX++;
                indexY++;
            }
        }
        for (int i = 0; i < matrix[0].size(); i++) {
            int indexX = i;
            int indexY = 0;
            int value = matrix[indexY][indexX];
            while (indexX < matrix[0].size() && indexY < matrix.size()) {
                if (matrix[indexY][indexX] != value) {
                    return false;
                }
                indexX++;
                indexY++;
            }
        }
        return true;
    }

    bool isCleanToeplitzMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        for (int i = 1; i < m; i++)
            for (int j = 1; j < n; j++)
                if (matrix[i][j] != matrix[i - 1][j - 1])
                    return false;
        return true;
    }
};