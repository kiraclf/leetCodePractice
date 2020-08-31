#include <iostream>
#include <vector>

using namespace std;
// 使用 DFS 深度优先遍历
// 先画出逻辑树，然后再继续解答
// 为了结果不能包含重复的组合，所以在进入到下一层时，选择的数都是从上一层选择的数开始
/// DFS 解决

/**
 * DFS:
 *  1. 递归终结条件
 *  2. 处理
 *  3. 清理
 */
class Solution {
 public:
  vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    // 0. Prepare
    vector<vector<int>> ans;
    sort(candidates.begin(), candidates.end());
    // 1. 遍历
    for (int i = 0; i < candidates.size(); i++) {
      // 递归
      vector<int> currentV = {candidates[i]};
      // DFS
      recursive(candidates[i], currentV, i, target, ans, candidates);
    }
    return ans;
  }

  void recursive(int currentSum, vector<int> currentV, int index, int target,
                 vector<vector<int>>& ansList, vector<int>& candidates) {
    // 递归终止条件
    if (currentSum > target) {
      return;
    }
    if (currentSum == target) {
      ansList.push_back(currentV);
      return;
    }
    for (int j = index; j < candidates.size(); j++) {
      currentV.push_back(candidates[j]);
      recursive(currentSum + candidates[j], currentV, j, target, ansList,
                candidates);
      currentV.pop_back();
    }
  }
};