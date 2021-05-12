#include <vector>
using namespace std;
/*
先使用 DFS 分区,然后找到最小的
*/
class Solution {
 private:
  vector<int> houses;
  vector<vector<int>> costList;
  int houseCount;
  int colorMax;
  int target;

 public:
  int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n,
              int target) {
    // 初始化结构
    this->houses = houses;
    this->costList = cost;
    this->target = target;
    this->houseCount = m;
    this->colorMax = n;
    // dfs 准备
    int minCost = INT_MAX;
    // dfs
    dfsPaint(0, 0, 0, minCost);
    // 返回
    return minCost == INT_MAX ? -1 : minCost;
  }

  void dfsPaint(int blockCount, int currentHouse, int cost, int& minCost) {
    /// terminator
    // 分区数大于目标
    if (blockCount > target) {
      return;
    }
    // 当前成本已经大于之前的最低成本
    if (minCost != INT_MAX && cost > minCost) {
      return;
    }
    // 当前房屋超过
    if (currentHouse >= houseCount) {
      if (blockCount == target) {
        minCost = min(cost, minCost);
      }
      return;
    }
    /// 粉刷当前房屋
    int currentColor = houses[currentHouse];
    if (currentColor != 0) {  // 当前无法粉刷
      if (currentHouse > 0 && houses[currentHouse - 1] == currentColor) {
        // 同一个街区
        dfsPaint(blockCount, currentHouse + 1, cost, minCost);
      } else {
        // 不同街区
        dfsPaint(blockCount + 1, currentHouse + 1, cost, minCost);
      }
    } else {
      // 当前可以粉刷
      // 第一个街区
      if (currentHouse == 0) {
        for (int i = 1; i <= colorMax; i++) {
          houses[currentHouse] = i;
          dfsPaint(blockCount + 1, currentHouse + 1,
                   cost + costList[currentHouse][i - 1], minCost);
          houses[currentHouse] = 0;
        }
        return;
      }
      // 新增一个街区
      int lastColor = houses[currentHouse - 1];
      for (int i = 1; i <= colorMax; i++) {
        if (i == lastColor) {
          continue;
        }
        houses[currentHouse] = i;
        dfsPaint(blockCount + 1, currentHouse + 1,
                 cost + costList[currentHouse][i - 1], minCost);
        houses[currentHouse] = 0;
      }
      // 沿用上一个街区
      houses[currentHouse] = lastColor;
      dfsPaint(blockCount, currentHouse + 1,
               cost + costList[currentHouse][lastColor - 1], minCost);
      houses[currentHouse] = 0;
    }
  }
};

int main() {
  Solution solve = Solution();
  vector<int> houses = {3,1,2,3};
  vector<vector<int>> cost = {{1,1,1}, {1,1,1,1}, {1,1,1,1}, {1,1,1,1}};
  int m = 4;
  int n = 3;
  int target = 3;
  int result = solve.minCost(houses, cost, m, n, target);
  return 0;
}