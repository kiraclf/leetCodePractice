#include <vector>
using namespace std;
class Solution {
 public:
  vector<int> findErrorNums(vector<int>& nums) {
    int size = nums.size();
    vector<int> integers(size, -1);
    int mismatchValue = -1;
    for (auto number : nums) {
      if (integers[number - 1] == -1) {
        integers[number - 1] = 1;
      } else {
        mismatchValue = number;
      }
    }
    int missingValue = -1;
    for (int i = 0; i < integers.size(); i++) {
      if (integers[i] == -1) {
        missingValue = i + 1;
        break;
      }
    }
    vector<int> result = { mismatchValue , missingValue};
    return result;
  }
};

int main() {
  Solution solve;
  vector<int> test = {1,1};
  vector<int> result = solve.findErrorNums(test);
  return 0;
}