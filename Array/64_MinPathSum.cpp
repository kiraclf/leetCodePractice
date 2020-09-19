#include <iostream>
#include <vector>
using namespace std;

/**
 * Given a m x n grid filled with non-negative numbers,
 * find a path from top left to bottom right which minimizes the sum of all
 * numbers along its path.
 *
 * Note: You can only move either down or right at any point in time.
 */

/**
 * 思路1:
 *  第一感觉还是一个 dp 的题目
 *  假设 dp(x, y) 表示 到该点的最小值, 则 dp(x , y) = min(dp(x - 1, y), dp(x, y
 * - 1)) + vector(x, y)
 */

class Solution {
 public:
  int minPathSum(vector<vector<int>>& grid) {
    // 0. 异常判断
    if (grid.size() == 0 || grid[1].size() == 0) return 0;
    // 特殊判断， 只有一个元素
    if (grid.size() == 1) {
      int sum = 0;
      for (auto value : grid[0]) {
        sum += value;
      }
      return sum;
    } else if (grid[0].size() == 1) {
      int sum = 0;
      for (int i = 0; i < grid.size(); i++) {
        sum += grid[i][0];
      }
      return sum;
    }
    // 1. 准备dp矩阵
    for (int i = 1; i < grid[1].size(); i++) {
      grid[0][i] += grid[0][i - 1];
    }
    for (int i = 1; i < grid.size(); i++) {
      grid[i][0] += grid[i - 1][0];
    }
    // 2. 生成dp矩阵
    for (int i = 1; i < grid[1].size(); i++) {
      for (int j = 1; j < grid.size(); j++) {
        grid[i][j] += min(grid[i - 1][j], grid[i][j - 1]);
      }
    }
    // 3. 返回
    return grid[grid.size() - 1][grid[0].size() - 1];
  }
};

int main() {
  Solution solve;
  vector<vector<int>> test = {{0}};
  cout << solve.minPathSum(test) << endl;
  return 0;
}
