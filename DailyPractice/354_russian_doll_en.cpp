#include <vector>
using namespace std;
/*
--- 题目描述 ---
给定一些标记了宽度和高度的信封，宽度和高度以整数对形式 (w,
h) 出现。
当另一个信封的宽度和高度都比这个信封大的时候，这个信封就可以放进另一个信封里，如同俄罗斯套娃一样。
请计算最多能有多少个信封能组成一组“俄罗斯套娃”信封（即可以把一个信封放到另一个信封里面）
--- 思路 ---
1. 将数组按照宽度排序
2. 要注意考虑宽高相同的情况无法叠加
--- 题解 ---
1. 前置题目 300 最长递增子序列
2. 重复元素的排序时,使用降序排列,从而杜绝严格递增的情况
*/

class Solution {
 public:
  int maxEnvelopes(vector<vector<int>>& envelopes) {
    sort(envelopes.begin(), envelopes.end(),sortFunc);
    vector<int> dp(envelopes.size(), 1);
    for (int i = 0; i < envelopes.size(); i++) {
      for (int j = 0; j < i; j++) {
        if (envelopes[i][1] > envelopes[j][1]) {
          dp[i] = max(dp[j] + 1, dp[i]);
        }
      }
    }
    int maxValue = 0;
    for (auto value : dp) {
      maxValue = max(value, maxValue);
    }
    return maxValue;
  }

  static bool sortFunc(const vector<int> &p1, const vector<int> &p2) {
    return p1[0] < p2[0] || (p1[0] == p2[0] && p1[1] > p2[1] ); 
  }
};