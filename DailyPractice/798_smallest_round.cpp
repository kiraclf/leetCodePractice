#include <vector>
using namespace std;
class Solution {
 public:
  int bestRotation(vector<int>& nums) {
    // k = n -1
    reverse(nums.begin(), nums.end());
    int ans = nums.size() - 1;

    int score = 0;
    for (int i = 0; i < nums.size(); i++) {
      if (nums[i] <= i) {
        score++;
      }
    }
    int maxScore = score;
    int lastIndex = nums.size() - 1;
    for (int k = nums.size() - 2; k >= 0; k--) {
      // have value in the before;
      bool usedToHaveValue = (nums[lastIndex] <= lastIndex);
      int nextScore = usedToHaveValue ? score - 1 : score;
      if (nums[lastIndex] <= 0) {
        nextScore++;
      }
      lastIndex--;
      if (nextScore >= maxScore) {
        ans = min(ans, k);
      }
    }
    return ans;
  }
};

int main() {
  Solution solve;
  vector<int> test = {2, 3, 1, 4, 0};
  int ans = solve.bestRotation(test);
  return 0;
}