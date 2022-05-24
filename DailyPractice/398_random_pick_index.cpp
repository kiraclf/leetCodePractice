#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
 private:
  unordered_map<int, vector<int>> cache;

 public:
  Solution(vector<int>& nums) {
    cache = {};
    for (int i = 0; i < nums.size(); i++) {
      cache[nums[i]].push_back(i);
    }
  }

  int pick(int target) {
    vector<int> list = cache[target];
    if (list.size() == 0) {
      return -1;
    }
    int randomIndex = rand() % list.size();
    return list[randomIndex];
  }
};