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

/// TODO: 本体存在最优解，需要重新解答