#include <vector>
#include <string>
using namespace std;

class Solution {
 public:
  vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    vector<vector<int>> res;
    vector<int> current;
    int size = nums.size();
    sort(nums.begin(), nums.end());
    vector<int> used(size, 0);
    dfsGenerate(nums, 0, current, used, res);
    return res;
  }

  void dfsGenerate(vector<int>& nums, int index, vector<int>& current, vector<int>& used, vector<vector<int>>& result) {
    result.push_back(current);
    int size = nums.size();
    for (int i = index; i < size; i++) {
      if (i > 0 && nums[i] == nums[i-1] && used[i] == 0) {
        continue;
      }
      used[i] = 1;
      current.push_back(nums[i]);
      dfsGenerate(nums, i+1, current, used, result);
      current.pop_back();
      used[i] = 0;
    }
  }
};

int main() {
  Solution solve;
  vector<int> question = {1,2,2};
  vector<vector<int>> result = solve.subsetsWithDup(question);
  return 0;
}