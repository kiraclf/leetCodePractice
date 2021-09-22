#include <string>
using namespace std;
class Solution {
 public:
  int lengthOfLastWord(string s) {
    int count = 0;
    int endIndex = s.size() - 1;
    while ( endIndex >= 0) {
      if (s[endIndex] == ' ') {
        if (count == 0) {
          endIndex--;
        } else {
          break;
        }
      } else {
        endIndex--;
        count++;
      }
    }
    return count;
  }
};

int main() {
  Solution solve;
  int count = solve.lengthOfLastWord("luffy is still joyboy");
  return 0;
}