#include <iostream>
#include <vector>

using namespace std;

/**
 * 1. 以中间为对称轴进行上下交换
 * 2. 以斜对称轴进行交换
 */
class Solution {
 public:
  void rotate(vector<vector<int>>& matrix) {
    int size = matrix.size();
    // top down reverse
    int start = 0;
    int end = size - 1;
    while (start < end) {
      swapVectors(matrix[start], matrix[end]);
      start++;
      end--;
    }
    // 对角线交换
    for (int i = 0; i < size; i++) {
      for (int j = i + 1; j < size; j++) {
        int temp = matrix[i][j];
        matrix[i][j] = matrix[j][i];
        matrix[j][i] = temp;
      }
    }
  }

  // 交换两个数组
  void swapVectors(vector<int>& a, vector<int>& b) {
    if (a.size() != b.size()) {
      return;
    }
    for (int i = 0; i < a.size(); i++) {
      int temp = a[i];
      a[i] = b[i];
      b[i] = temp;
    }
  }
};