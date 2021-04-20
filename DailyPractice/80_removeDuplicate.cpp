#include <vector>
using namespace std;
class Solution {
 public:
  int removeDuplicates(vector<int>& nums) {
    int emptyValue = -10001;
    int duplicateCount = 1;
    int beforeValue = emptyValue;
    int removeCount = 0;
    // check duplicate, make duplicate value -10001.
    for (int i = 0; i < nums.size(); i++) {
      if (beforeValue == emptyValue) {
        beforeValue = nums[i];
        duplicateCount = 1;
        continue;
      }
      if (beforeValue == nums[i]) {
        if (duplicateCount == 2) {
          removeCount++;
          nums[i] = emptyValue;
          duplicateCount = 2;
        } else {
          duplicateCount++;
        }
      } else {
        beforeValue = nums[i];
        duplicateCount = 1;
      }
    }
    // reform list
    for (int i = 0; i < nums.size() - removeCount; i++) {
      if (nums[i] == emptyValue) {
        int currentIndex = i + 1;
        while (currentIndex < nums.size()) {
          if (nums[currentIndex] != emptyValue) {
            nums[i] = nums[currentIndex];
            nums[currentIndex] = emptyValue;
            break;
          }
          currentIndex++;
        }
      }
    }
    return (int)nums.size() - duplicateCount;
    }

    int removeDuplicatesOfficial(vector<int>& nums) {
      if (nums.size() <= 2) {
        return nums.size();
      }
      int slow = 2;
      int fast = 2;
      while (fast < nums.size()) {
        if (nums[fast] != nums[slow-2]) {
          nums[slow] = nums[fast];
          slow++;
        }
        fast++;
      }
      return slow;
    }
};

int main() {
  Solution solve;
  vector<int> test = {1, 1, 1, 2, 2, 3};
  int result = solve.removeDuplicates(test);
  return 0;
}