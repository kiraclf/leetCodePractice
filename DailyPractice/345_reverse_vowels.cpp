#include <string>
#include <unordered_set>
using namespace std;
class Solution {
 public:
  string reverseVowels(string s) {
    unordered_set<char> reverseSet = {'a', 'A', 'e', 'E', 'i', 'I', 'o', 'O', 'u', 'U'};
    if (s.size() == 0) {
      return "";
    }
    int startIndex = 0;
    int endIndex = s.size() - 1;
    while (startIndex < endIndex) {
      char startCurrentChar = s[startIndex];
      if (reverseSet.find(startCurrentChar) == reverseSet.end()) {
        startIndex++;
        continue;
      } else {
        // move start index to find match
        while (endIndex > startIndex) {
          char endCurrentChar = s[endIndex];
          if (reverseSet.find(endCurrentChar) == reverseSet.end()) {
            endIndex--;
            continue;
          } else {
            // reverse
            s[startIndex] = endCurrentChar;
            s[endIndex] = startCurrentChar;
            endIndex--;
            startIndex++;
            break;
          }
        }
      }
    }
    return s;
  }
};

int main() {
  Solution solve;
  string ans = solve.reverseVowels("ai");
  return 0;
}