#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Solution {
 public:
  int maxDepth(string s) {
    int leftCount = 0;
    int maxDepth = 0;
    for (int i = 0; i < s.size(); i++) {
      if (s[i] == '(') {
        leftCount++;
        maxDepth = max(maxDepth, leftCount);
      } else if (s[i] == ')') {
        leftCount -= 1;
      }
    }
    return maxDepth;
  }
};

int main() {
  Solution solution;
  vector<string> tests = {"(1+(2*3)+((8)/4))+1", "(1)+((2))+(((3)))",
                          "1+(2*3)/(2-1)", "1"};
  for (auto test : tests) {
    int result = solution.maxDepth(test);
    std::cout << result << std::endl;
  }
  return 0;
}