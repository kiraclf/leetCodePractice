/*
A robot is located at the top-left corner of a m x n grid (marked 'Start' in the
diagram below). The robot can only move either down or right at any point in
time. The robot is trying to reach the bottom-right corner of the grid (marked
'Finish' in the diagram below). How many possible unique paths are there?
*/

#include <iostream>
#include <vector>

using namespace std;

/**
 * 思路1:
 *  直接使用 DFS 进行深度优先的搜索，找到需要的路径
 *
 * 官方题解:
 *  本题因为并不需要输出答案数组，因此不需要使用死递归 --> 使用 DP 方程来解决
 *  假设到最后一个格子的解为 n， 那么 p[i - 1][j - 1] = p[i - 1 - 1][j - 1] +
 * p[i - 1][j - 2] 则可以推导出状态转移方程，且 p[i][0] = 1 p[0][j] = 1
 * 因此可以用1来初始化
 *
 * 总结:
 *  当答案只是求个数时，优先考虑 dp，关键在于如何找出转移方程
 */

class Solution {
 public:
  int uniquePaths(int m, int n) {
    int total = 0;
    vector<int> point = {0, 0};
    dfsSerach(point, m, n, total);
    return total;
  }

  void dfsSerach(vector<int> point, int m, int n, int &total) {
    // terminator
    if (point[0] == m - 1 && point[1] == n - 1) {
      total += 1;
      return;
    }
    if (point[0] > m - 1 || point[1] > n - 1) {
      return;
    }
    // go right
    point[1] += 1;
    dfsSerach(point, m, n, total);
    // go down
    point[1] -= 1;
    point[0] += 1;
    dfsSerach(point, m, n, total);
  }

  int officialUniquePaths(int m, int n) {
    // 创建 dp 数组
    vector<vector<int>> list(m, vector<int>(n, 1));
    // 遍历
    for (int i = 1; i < m; i++) {
      for (int j = 1; j < n; j++) {
        list[i][j] = list[i - 1][j] + list[i][j - 1];
      }
    }
    return list[m - 1][n - 1];
  }
};