/*
你准备参加一场远足活动。给你一个二维 rows x
columns 的地图 heights ，其中 heights[row][col] 表示格子 (row,
col) 的高度。一开始你在最左上角的格子 (0, 0) ，且你希望去最右下角的格子 (rows-1,
columns-1) （注意下标从 0 开始编号）。你每次可以往
上，下，左，右 四个方向之一移动，你想要找到耗费 体力 最小的一条路径。

一条路径耗费的 体力值 是路径上相邻格子之间 高度差绝对值 的 最大值 决定的。

请你返回从左上角走到右下角的最小 体力消耗值 。
*/

#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
 public:
  // 暴力求解, dfs
  // 暴力求解超时-------
  int minimumEffortPath(vector<vector<int>> &heights) {
    int yCount = heights.size();
    int xCount = yCount > 0 ? heights[0].size() : 0;
    if (xCount == 0 || yCount == 0) {
      return 0;
    }
    int smallest = INT_MAX;
    unordered_set<int> visited;
    visited.insert(0);
    dfs(0, 0, yCount - 1, xCount - 1, 0, heights, smallest, visited);
    return smallest;
  }

  void dfs(int firstIndex, int secondIndex, int firstMax, int secondMax,
           int currentStrength, vector<vector<int>> &heights, int &smallest,
           unordered_set<int> visited) {
    if (firstIndex == firstMax && secondIndex == secondMax) {
      // The end
      printf("end\n");
      smallest = min(smallest, currentStrength);
      return;
    }
    if (smallest != INT_MAX) {
      if (currentStrength >= smallest) {
        printf("end\n");
        return;
      }
    }
    // top
    if (firstIndex > 0) {
      int index = secondIndex + (firstIndex - 1) * (secondMax + 1);
      if (visited.find(index) != visited.end()) {
      } else {
        printf("top\n");
        visited.insert(index);
        int strength = cacluateAbsStrength(
            firstIndex, secondIndex, firstIndex - 1, secondIndex, heights);
        dfs(firstIndex - 1, secondIndex, firstMax, secondMax,
            max(strength, currentStrength), heights, smallest, visited);
        visited.erase(index);
      }
    }
    // down
    if (firstIndex < firstMax) {
      int index = secondIndex + (firstIndex + 1) * (secondMax + 1);
      if (visited.find(index) != visited.end()) {
      } else {
        printf("down\n");
        visited.insert(index);
        int strength = cacluateAbsStrength(
            firstIndex, secondIndex, firstIndex + 1, secondIndex, heights);
        dfs(firstIndex + 1, secondIndex, firstMax, secondMax,
            max(strength, currentStrength), heights, smallest, visited);
        visited.erase(index);
      }
    }
    // left
    if (secondIndex > 0) {
      int index = secondIndex - 1 + firstIndex * (secondMax + 1);
      if (visited.find(index) != visited.end()) {
      } else {
        printf("left\n");
        visited.insert(index);
        int strength = cacluateAbsStrength(firstIndex, secondIndex - 1,
                                           firstIndex, secondIndex, heights);
        dfs(firstIndex, secondIndex - 1, firstMax, secondMax,
            max(strength, currentStrength), heights, smallest, visited);
        visited.erase(index);
      }
    }
    // right
    if (secondIndex < secondMax) {
      int index = secondIndex + 1 + firstIndex * (secondMax + 1);
      if (visited.find(index) != visited.end()) {
      } else {
        printf("right\n");
        visited.insert(index);
        int strength = cacluateAbsStrength(firstIndex, secondIndex + 1,
                                           firstIndex, secondIndex, heights);
        dfs(firstIndex, secondIndex + 1, firstMax, secondMax,
            max(strength, currentStrength), heights, smallest, visited);
        visited.erase(index);
      }
    }
  }

  int cacluateAbsStrength(int firstIndex, int secondIndex, int newFirst,
                          int newSecond, vector<vector<int>> &heights) {
    int currentValue = heights[firstIndex][secondIndex];
    int targetValue = heights[newFirst][newSecond];
    return abs(currentValue - targetValue);
  }
};

int main() {
  vector<vector<int>> test = {{1, 2, 1, 1, 1},
                              {1, 2, 1, 2, 1},
                              {1, 2, 1, 2, 1},
                              {1, 2, 1, 2, 1},
                              {1, 1, 1, 2, 1}};
  Solution solve;
  int result = solve.minimumEffortPath(test);
  printf("%i\n", result);
  return 0;
}
