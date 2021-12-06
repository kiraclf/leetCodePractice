#include <string>
#include <vector>
using namespace std;
class Solution {
 public:
  string truncateSentence(string s, int k) {
    if (k == 0) {
      return "";
    }
    int length = 1;
    int count = 0;
    while (count < k && length <= s.size()) {
      if (s[length - 1] == ' ') {
        count++;
        if (count == k) {
          length--;
          break;
        }
      }
      length++;
    }
    return s.substr(0, length);
  }
};

int main() {
  Solution solve;
  string test = "What is the solution to this problem";
  string res = solve.truncateSentence(test, 4);
  return 0;
}