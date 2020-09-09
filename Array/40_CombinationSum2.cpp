#include <iostream>
#include <set>
#include <vector>
using namespace std;

/**
 * 思路：
 *  类似于 39 题，仍然使用深度优先搜索，但是不再使用重复的数字
 */
class Solution {
 public:
  vector<vector<int>> combinationSum2(vector<int> &candidates, int target) {
    vector<vector<int>> ans;
    sort(candidates.begin(), candidates.end());
    for (int i = 0; i < candidates.size(); i++) {
      vector<int> current = {candidates[i]};
      set<int> used = {candidates[i]};
      recursive(target, ans, current, candidates[i], used, i, candidates);
    }
    return ans;
  }

  void recursive(int target, vector<vector<int>> &ansList,
                 vector<int> &currentList, int sum, set<int> &used,
                 int currentIndex, vector<int> &candidates) {
    if (sum > target) return;
    if (sum == target) {
      ansList.push_back(currentList);
      return;
    }
    for (int i = currentIndex + 1; i < candidates.size(); i++) {
      if (used.find(candidates[i]) == used.end()) {
        used.insert(candidates[i]);
        currentList.push_back(candidates[i]);
        recursive(target, ansList, currentList, sum + candidates[i], used, i,
                  candidates);
        used.erase(candidates[i]);
        currentList.pop_back();
      }
    }
  }
};