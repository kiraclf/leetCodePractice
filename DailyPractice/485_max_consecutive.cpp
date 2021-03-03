#include <vector>
using namespace std;
class Solution {
 public:
  int findMaxConsecutiveOnes(vector<int>& nums) {
    int size = nums.size();
    if (size <= 0) {
      return 0;
    }
    int result = 0;
    int start = 0;
    while ( start < size ) {
      if (nums[start] == 1) {
        int length = 0;
        while (start + length < size) {
          if (nums[start+length] == 1) {
            length++;
          } else {
            break;
          }
        }
        result = max(result, length);
        start = start + length;
      } else {
        start++;
      }
    }
    return result;
  }
};

int main() {
  vector<int> test = {1,1,0,1,1,1};
  Solution solve;
  int result = solve.findMaxConsecutiveOnes(test);
  return 0;
}