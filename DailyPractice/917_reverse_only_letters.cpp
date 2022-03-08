#include <string>
#include <vector>
using namespace std;
class Solution {
 public:
  string reverseOnlyLetters(string s) {
    int startIndex = 0;
    int endIndex = s.size() - 1;
    while (startIndex < s.size() && !isAlpha(s[startIndex])) {
      startIndex++;
    }
    while (endIndex >= 0 && !isAlpha(s[endIndex])) {
      endIndex--;
    }
    while (startIndex < s.size() && endIndex >= 0 && startIndex <= endIndex) {
      char temp = s[startIndex];
      s[startIndex] = s[endIndex];
      s[endIndex] = temp;
      startIndex++;
      endIndex--;
      while (startIndex < s.size() && !isAlpha(s[startIndex])) {
        startIndex++;
      }
      while (endIndex >= 0 && !isAlpha(s[endIndex])) {
        endIndex--;
      }
    }
    return s;
  }

  bool isAlpha(char character) {
    return (character >= 'a' && character <= 'z') ||
           (character >= 'A' && character <= 'Z');
  }
};

int main() {
  Solution solve;
  string test = "-";
  string reso = solve.reverseOnlyLetters(test);
  return 0;
}