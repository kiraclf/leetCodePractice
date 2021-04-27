#include <vector>
using namespace std;
class Solution {
 public:
  vector<int> largestDivisibleSubset(vector<int>& nums) {
    // Exception handle
    int size = nums.size();
    if (size == 0) {
      return nums;
    }
    // Sub set
    vector<int> ans;
    vector<int> current;
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size(); i++) {
      dfs(nums, current, i, ans);
    }
    return ans;
  }

  void dfs(vector<int>& nums, vector<int> current, int currentIndex, vector<int> &ans) {
    // process
    if (current.size() == 0) {
      current.push_back(nums[currentIndex]);
    } else {
      bool canAdd = true;
      for (int i = 0; i < current.size(); i++) {
        int remain = nums[currentIndex] % current[i];
        if (remain != 0) {
          // can't add
          canAdd = false;
          break;
        }
      }
      if (canAdd) {
        current.push_back(nums[currentIndex]);
      }
    }
    if (currentIndex == nums.size() - 1) {
      ans = ans.size() < current.size() ? current : ans;
      return;
    }
    // next
    for (int i = currentIndex + 1; i < nums.size(); i++) {
      dfs(nums, current, i, ans);
    }
  }
};

int main() {
  Solution solve;
  vector<int> test = {5, 9, 18, 54, 108, 540, 90, 180, 360, 720};
  vector<int> result = solve.largestDivisibleSubset(test);
  return 0;
}