#include <iostream>
#include <vector>

using namespace std;

/**
 * 题目:
 * 一个机器人位于一个 m x n 网格的左上角 （起始点在下图中标记为“Start” ）。
 * 机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为“Finish”）。
 * 现在考虑网格中有障碍物。那么从左上角到右下角将会有多少条不同的路径？
 *
 * 思路1:
 *  1. 首先查看最上层是否有遮盖点，如果有，则初始化之后的数值为0
 *  2. 查看最左侧是否有遮盖点，如果有，则初始化后续的数值为0
 *  3. 遍历之后的剩余的点，如果值为1，则有遮盖，将自己的值设为0
 *  4. 返回最后的答案
 *
 * 难点：
 *  1. 这里的判断在首位元素出现了问题
 *  2. 判断条件的顺序需要注意一下，开始出现了错误
 */

class Solution {
 public:
  int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    // 0. 异常判断
    if (obstacleGrid.size() == 0 || obstacleGrid[0].size() == 0) {
      return 0;
    }
    // 检测开头是否为1
    if (obstacleGrid[0][0] == 1) {
      return 0;
    }
    // 1. 检查上方数组
    int topObstacleIndex = 0;
    while (topObstacleIndex < obstacleGrid[0].size() &&
           obstacleGrid[0][topObstacleIndex] != 1) {
      obstacleGrid[0][topObstacleIndex] = 1;
      topObstacleIndex++;
    }
    if (topObstacleIndex < obstacleGrid[0].size()) {
      for (int i = topObstacleIndex; i < obstacleGrid[0].size(); i++) {
        obstacleGrid[0][i] = 0;
      }
    }
    // 2. 检查左侧数组
    int leftObstacelIndex = 1;
    while (leftObstacelIndex < obstacleGrid.size() &&
           obstacleGrid[leftObstacelIndex][0] != 1) {
      obstacleGrid[leftObstacelIndex][0] = 1;
      leftObstacelIndex++;
    }
    if (leftObstacelIndex < obstacleGrid.size()) {
      for (int i = leftObstacelIndex; i < obstacleGrid.size(); i++) {
        obstacleGrid[i][0] = 0;
      }
    }
    // 3. 遍历元素
    for (int i = 1; i < obstacleGrid.size(); i++) {
      for (int j = 1; j < obstacleGrid[0].size(); j++) {
        if (obstacleGrid[i][j] == 1) {
          obstacleGrid[i][j] = 0;
        } else {
          obstacleGrid[i][j] = obstacleGrid[i - 1][j] + obstacleGrid[i][j - 1];
        }
      }
    }
    // 4. 返回最后一个元素
    int xSize = obstacleGrid.size();
    int ySize = obstacleGrid[0].size();
    return obstacleGrid[xSize - 1][ySize - 1];
  }
};

int main() {
  Solution test;
  vector<vector<int>> testV = {{0, 0, 0}, {0, 1, 0}, {0, 0, 0}};
  test.uniquePathsWithObstacles(testV);
  return 0;
}
