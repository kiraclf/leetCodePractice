#include <vector>
using namespace std;
class Solution {
 public:
  vector<int> sortArrayByParity(vector<int>& nums) {
    int evenIndex = 0;
    int currentIndex = 0;
    while (currentIndex < nums.size()) {
      if (nums[currentIndex] % 2 == 0) {
        // even
        if (evenIndex != currentIndex) {
          int temp = nums[evenIndex];
          nums[evenIndex] = nums[currentIndex];
          nums[currentIndex] = temp;
        }
        evenIndex++;
      }
      currentIndex++;
    }
    return nums;
  }
};

int main() {
  Solution solve;
  vector<int> test = {0};
  auto res = solve.sortArrayByParity(test);
  return 0;
}