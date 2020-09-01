#include <iostream>
#include <vector>

using namespace std;

/**
 * 这里的要求是需要不重复的解，首先确定需要使用 DFS
 * 同时，这里可能出现同样的元素，且每个元素只能使用一次
 * 因此，通过排序，可以消除同样的元素的问题（跳过相同的）
 */

class Solution {
 public:
  vector<vector<int>> combinationSum2(vector<int> &candidates, int target) {
    sort(candidates.begin(), candidates.end());
    vector<vector<int>> ansList;
    vector<int> current;
    dfsCombination(ansList, current, candidates, target, 0, 0);
    return ansList;
  }

  void dfsCombination(vector<vector<int>> &ansList, vector<int> &currentList,
                      vector<int> &candidates, int target, int currentIndex,
                      int sum) {
    if (sum == target) {
      ansList.push_back(currentList);
    }
    if (sum > target) {
      return;
    }
    for (int j = currentIndex; j < candidates.size(); j++) {
      /*
       * 难点在于理解此处的 j > currentIndex;
       * j > currentIndex 表示 j - 1 已经被添加过了
       * candidate[j] == candidates[j - 1] 表示 该重复，因此该情况需要被忽略
       * 这种处理还是非常巧妙的
       */
      if (j > currentIndex && candidates[j] == candidates[j - 1]) {
        continue;
      }
      currentList.push_back(candidates[j]);
      dfsCombination(ansList, currentList, candidates, target, j + 1,
                     sum + candidates[j]);
      currentList.pop_back();
    }
  }
};