#include <iostream>
#include <vector>

using namespace std;

/**
 * 题目描述：
 *  Given a collection of integers that might contain duplicates, nums, return
 * all possible subsets (the power set). Note: The solution set must not contain
 * duplicate subsets.
 */

/**
 * 思考:
 *  还是寻找子集的问题的，因此还是需要使用 DFS 进行遍历，问题在于重复的元素处理
 *
 * 思路1:
 *  以数组的长度，进行遍历，然后在遍历时增加缓存数组，判断是否重复
 */

class Solution {
 public:
  vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    vector<vector<int>> ans;
    // sort
    sort(nums.begin(), nums.end());
    // Dfs
    vector<int> current;
    dfsDup(ans, current, nums, 0);
    return ans;
  }

  void dfsDup(vector<vector<int>>& ans, vector<int>& current, vector<int>& nums,
              int currentIndex) {
    ans.push_back(current);
    for (int i = currentIndex; i < nums.size(); i++) {
      if (i > currentIndex && nums[i] == nums[i - 1]) {
        continue;
      }
      current.push_back(nums[i]);
      dfsDup(ans, current, nums, i);
      current.pop_back();
    }
  }

  // DFS 进行搜索
  vector<vector<int>> dfsSolution(vector<int>& nums) {
    vector<vector<int>> ans;
    vector<int> current;
    sort(nums.begin(), nums.end());
    myDfs(current, ans, 0, nums);
    return ans;
  }

  void myDfs(vector<int>& current, vector<vector<int>>& ans, int currentIndex,
             vector<int>& nums) {
    ans.push_back(current);
    for (int i = currentIndex; i < nums.size(); i++) {
      if (i > currentIndex && nums[i] == nums[i - 1]) {
        continue;
      }
      current.push_back(nums[i]);
      myDfs(current, ans, i + 1, nums);
      current.pop_back();
    }
  }
};