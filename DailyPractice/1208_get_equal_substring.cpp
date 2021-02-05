#include <string>
#include <vector>
using namespace std;

class Solution {
 public:
  int equalSubstring(string s, string t, int maxCost) {
    // sliding window
    int startIndex = 0;
    int endIndex = 0;
    int costSum = 0;
    int maxSize = 0;
    while (endIndex < s.size()) {
      costSum += abs(s[endIndex] - t[endIndex]);
      if (costSum > maxCost) {
        // shift left, right
        costSum -= abs(s[startIndex] - t[startIndex]);
        startIndex++;
        endIndex++;
      } else {
        // shift right
        maxSize++;
        endIndex++;
      }
    }
    return maxSize;
  }
};

int main() {
  Solution test;
  int result = test.equalSubstring("abcd", "cdef", 3);
  return 0;
}