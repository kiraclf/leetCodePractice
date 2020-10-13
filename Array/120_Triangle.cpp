/**
 * 描述
 * Given a triangle, find the minimum path sum from top to bottom.
 * Each step you may move to adjacent numbers on the row below.
 */
#include <vector>
using namespace std;

class Solution {
 public:
  int minimumTotal(vector<vector<int>>& triangle) {
    int ans = INT_MAX;
    // 或者需要以下特殊情况的判断
    dfsSearch(-1, 0, triangle, 0, ans);
    return ans;
  }

  /**
   * 使用 DFS 的确可以获得答案，但是不能通过测试，时间复杂度过高
   */
  void dfsSearch(int depth, int sum, vector<vector<int>>& triangle, int index,
                 int& ans) {
    if (depth == triangle.size() - 1) {
      ans = min(ans, sum);
      return;
    }
    // left
    sum = sum + triangle[depth + 1][index];
    dfsSearch(depth + 1, sum, triangle, index, ans);
    sum = sum - triangle[depth + 1][index];
    // right
    if (index + 1 < triangle[depth + 1].size()) {
      sum = sum + triangle[depth + 1][index + 1];
      dfsSearch(depth + 1, sum, triangle, index + 1, ans);
    }
  }

  /**
   * 使用 DP 来对该题进行分析
   * f[i][j] 表示从顶点到点[i][j] 的最小值，由于只能选择相邻的点因此得到状态转移方程
   * f[i][j] = min(f[i-1][j-1], f[i-1][j]) + num[i][j]
   * 开始条件为 f[0][0] = nums[0][0]
   * 如此便可以解决
  */
  int minimumTotalDP(vector<vector<int>>& triangle) {
    int n = triangle.size();
    // 状态转移二维数组
    vector<vector<int>> f(n, vector<int>(n));
    f[0][0] = triangle[0][0];
    for (int i = 1; i < n; ++i) {
      f[i][0] = f[i - 1][0] + triangle[i][0];
      for (int j = 1; j < i; ++j) {
        f[i][j] = min(f[i - 1][j - 1], f[i - 1][j]) + triangle[i][j];
      }
      f[i][i] = f[i - 1][i - 1] + triangle[i][i];
    }
    return *min_element(f[n - 1].begin(), f[n - 1].end());
  }
};