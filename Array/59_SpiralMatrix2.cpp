/**
 * 题目: 给定一个正整数 n，生成一个包含 1 到 n2
 * 所有元素，且元素按顺时针顺序螺旋排列的正方形矩阵。
 *
 * 思路1：
 *  1. 生成所有的元素矩阵
 *  2. 顺时针旋转矩阵
 *
 * 思路2：(优先选用此方法)
 *  1. 生成答案数组
 *  2. 遍历元素，添加
 *
 * 难点：
 *  在于边界条件的添加以及判断，还有长度为1时的情况需要特殊判断
 * 启示：
 *  1. 边界条件 0 和 1 需要特殊判断
 *  2. 条件需要统一，防止遍历时出错
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<vector<int>> generateMatrix(int n) {
    if (n == 0) return vector<vector<int>>{};
    // 1. 生成答案数组
    vector<vector<int>> ans = vector<vector<int>>(n, vector<int>(n, 0));
    // 2. 遍历层
    int currentLength = n;
    int value = 1;
    int process = 0;
    while (currentLength > 0) {
      if (currentLength == 1) {
        ans[process][process] = value;
        break;
      }
      for (int i = 0; i < currentLength - 1; i++) {
        ans[process][i + process] = value;
        value++;
      }
      for (int i = 0; i < currentLength - 1; i++) {
        ans[process + i][n - process - 1] = value;
        value++;
      }
      for (int i = 0; i < currentLength - 1; i++) {
        ans[n - process - 1][n - i - 1 - process] = value;
        value++;
      }
      for (int i = 0; i < currentLength - 1; i++) {
        ans[n - 1 - i - process][process] = value;
        value++;
      }
      currentLength -= 2;
      process++;
    }
    // 返回
    return ans;
  }
};

int main() {
  Solution test;
  test.generateMatrix(3);
}