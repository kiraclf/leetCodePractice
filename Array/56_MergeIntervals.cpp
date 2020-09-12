#include <iostream>
#include <vector>

using namespace std;

/**
 * 思路1：
 *  1. 遍历每个元素
 *  2. 不断比对该元素，直到没有重复空间， i++, 移除 遍历的元素
 */

class Solution {
 public:
  vector<vector<int>> merge(vector<vector<int>> &intervals) {
    // 异常判断
    if (intervals.size() < 2) return intervals;
    // 遍历
    int startIndex = 0;
    vector<int> duplicate = {1, 1, 1};
    while (startIndex < intervals.size()) {
      if (intervals[startIndex] == duplicate) {
        startIndex++;
        continue;
      }
      bool changed = false;
      for (int i = startIndex + 1; i < intervals.size(); i++) {
        if (intervals[i] == duplicate) {
          continue;
        }
        if (haveIntervals(intervals[startIndex], intervals[i])) {
          intervals[startIndex] =
              mergeIntervals(intervals[startIndex], intervals[i]);
          intervals[i] = duplicate;
          changed = true;
        }
      }
      if (!changed) {
        startIndex++;
      }
    }
    // 产生返回数组
    vector<vector<int>> ans;
    for (auto value : intervals) {
      if (value != duplicate) {
        ans.push_back(value);
      }
    }
    return ans;
  }

  bool haveIntervals(vector<int> &arrA, vector<int> &arrB) {
    // A 的 最小值 > B 的最大值 || A  的 最大值 < B 的 最小值
    return !(arrA[0] > arrB[1] || arrA[1] < arrB[0]);
  }

  // 合并两个vector
  vector<int> mergeIntervals(vector<int> &arrA, vector<int> &arrB) {
    int start = min(arrA[0], arrB[0]);
    int end = max(arrA[1], arrB[1]);
    return vector<int>{start, end};
  }

  /**
   * 官方思路:
   *    1. 先将vector按照左边的顺序进行排序
   *    2. 创建 答案数组，将第一个元素放入答案数组
   *    3.
   * 如果新加入的左边大于当前栈顶的最大值则直接加入，否则有重合，取其最大值更新数组
   */

  vector<vector<int>> officialSolution(vector<vector<int>> &intervals) {
    // 异常判断
    if (intervals.size() < 2) return intervals;
    // 将数组排序
    sort(intervals.begin(), intervals.end());
    // 创建答案数组
    vector<vector<int>> ans;
    ans.push_back(intervals[0]);
    int next = 1;
    while (next < intervals.size()) {
      if (intervals[next][0] > ans.back()[1]) {
        ans.push_back(intervals[next]);
      } else {
        int maxValue = max(intervals[next][1], ans.back()[1]);
        ans.back()[1] = maxValue;
      }
      next++;
    }
    return ans;
  }
};

int main() {
  vector<vector<int>> toTest = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
  Solution test;
  vector<vector<int>> ans = test.merge(toTest);
  return 0;
}