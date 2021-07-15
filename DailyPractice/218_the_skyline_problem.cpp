#include <vector>
#include <queue>
using namespace std;
class Solution {
 public:
  vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
    // 创建 priority queue, 按照高度排序的方法
    auto cmp = [](const pair<int, int>& a, const pair<int, int>& b) -> bool {
      return a.second < b.second;
    };
    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> que(cmp);
    // 排序关键点
    vector<int> boundaries;
    for (auto& building : buildings) {
      // 左端点
      boundaries.push_back(building[0]);
      // 右端点
      boundaries.push_back(building[1]);
    }
    sort(boundaries.begin(), boundaries.end());
    // 答案准备
    vector<vector<int>> ret;
    // 遍历关键点
    int n = buildings.size(), idx = 0;
    for (auto& boundary : boundaries) {
      // 将对应的右端点入栈
      while (idx < n && buildings[idx][0] <= boundary) {
        que.emplace(buildings[idx][1], buildings[idx][2]);
        idx++;
      }
      // 这里延迟删除不符合的右端点
      while (!que.empty() && que.top().first <= boundary) {
        que.pop();
      }
      int maxn = que.empty() ? 0 : que.top().second;
      if (ret.size() == 0 || maxn != ret.back()[1]) {
        ret.push_back({boundary, maxn});
      }
    }
    return ret;
  }
};