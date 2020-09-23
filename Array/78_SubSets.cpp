#include <iostream>
#include <vector>

using namespace std;

/**
 * Given a set of distinct integers, nums,
 * return all possible subsets (the power set).
 *
 * 思路1:
 *  深度优先进行搜索
 *
 *
 * 迭代法实现枚举:
 *  假设每个元素的状态为 0 - 在 , 1 - 不在
 *  则每个状态都可以用 n 个数来表示，则值为 0 -> 2^n - 1
 *  因此可以通过此来构造状态，然后添加到数组中
 */
class Solution {
 public:
  vector<vector<int>> subsets(vector<int> &nums) {
    vector<vector<int>> ans;
    ans.push_back({});
    dfsSearch({}, ans, nums, 0);
    return ans;
  }

  vector<vector<int>> numberSum(vector<int> &nums) {
    vector<int> current;
    vector<vector<int>> ans;
    int size = nums.size();
    for (int mask = 0; mask < (1 << size); ++mask) {
      current.clear();
      for (int i = 0; i < size; ++i) {
        if (mask & (1 << i)) {
          current.push_back(nums[i]);
        }
      }
      ans.push_back(current);
    }
    return ans;
  }

  void dfsSearch(vector<int> current, vector<vector<int>> &sums,
                 vector<int> &nums, int startIndex) {
    cout << startIndex << endl;
    if (startIndex >= nums.size()) {
      return;
    }
    sums.push_back(current);
    for (int i = startIndex + 1; i < nums.size(); i++) {
      current.push_back(nums[i]);
      dfsSearch(current, sums, nums, i);
      cout << i << endl;
      current.pop_back();
    }
  }
};

int main() {
  vector<int> test = {1, 2, 3};
  Solution solve;
  solve.subsets(test);
  return 0;
}