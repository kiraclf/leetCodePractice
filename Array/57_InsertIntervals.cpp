#include <iostream>
#include <vector>

using namespace std;

/**
 * 基本思路:
 *  1. 先找到对应的插入位置
 *  2. 插入后对整个数组进行 mergeIntervals
 */
class Solution {
 public:
  vector<vector<int>> insert(vector<vector<int>>& intervals,
                             vector<int>& newInterval) {
    // 0. 异常判断
    if (intervals.size() == 0) {
      return {newInterval};
    }
    // 1. 找到对应的 插入位置
    int addSmall = newInterval[0];
    for (int i = 0; i < intervals.size(); i++) {
      int interSamll = intervals[i][0];
      // 开头就比最小值小,则插入到最前面
      if (i == 0) {
        if (addSmall <= interSamll) {
          intervals.insert(intervals.begin(), newInterval);
          break;
        }
      }
      // 大于当前最小值时，插入到前面
      if (addSmall <= interSamll) {
        intervals.insert(intervals.begin() + i, newInterval);
        break;
      }
      // 开头就比最后一个最小值大，则插入到最后面
      if (i == intervals.size() - 1) {
        if (addSmall >= interSamll) {
          intervals.push_back(newInterval);
          break;
        }
      }
    }
    // 2. 重新 merge 当前的 intervals
    vector<vector<int>> ans;
    ans.push_back(intervals[0]);
    int currentIndex = 1;
    while (currentIndex < intervals.size()) {
      if (intervals[currentIndex][0] > ans.back()[1]) {
        ans.push_back(intervals[currentIndex]);
      } else {
        ans.back()[1] = max(ans.back()[1], intervals[currentIndex][1]);
      }
      currentIndex++;
    }
    return ans;
  }
};

/// 官方题解
/**
 * 其实就是上述方法的优化。
 * 1. 添加 newInterval 之前的元素到答案数组中
 * 2. 添加 newInterval 到答案数组中，其中，如果有重合的地方则进行合并
 * 3.
 * 继续添加之后的元素，需要不断与之前的进行判断是否需要合并，如果不需要合并则添加
 *
 * 隐藏的优化：
 *  如果添加新元素后，有一次没有进行合并，则后续的都不需要合并了，直接进行添加
 */
