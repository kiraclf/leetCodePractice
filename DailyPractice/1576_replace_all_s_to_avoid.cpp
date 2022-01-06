#include <string>
using namespace std;
class Solution {
 public:
  string modifyString(string s) {
    if (s.size() == 0) {
      return s;
    }
    s.push_back('!');
    int startIndex = 0;
    int questionCount = 0;
    bool beforeHaveQuestion = false;
    char before = '!';
    char end;
    while (startIndex < s.size()) {
      if (s[startIndex] != '?' && !beforeHaveQuestion) {
        questionCount = 0;
        before = s[startIndex];
      } else if (s[startIndex] != '?' && beforeHaveQuestion) {
        end = s[startIndex];
        for (int i = startIndex - questionCount; i < startIndex; i++) {
          if (i == startIndex - questionCount && questionCount == 1) {
            char beforeChar = before;
            for (int j = 0; j < 26; j++) {
              char currentSelect = 'a' + j;
              if (currentSelect != beforeChar && currentSelect != end) {
                s[i] = currentSelect;
                break;
              }
            }
          } else if (i == startIndex - questionCount) {
            // different than first
            if (before == '!') {
              s[i] = 'a';
            } else {
              if (before != 'z') {
                s[i] = before + 1;
              } else {
                s[i] = 'a';
              }
            }
          } else if (i == startIndex - 1) {
            // different than before and end
            char beforeChar = s[i - 1];
            for (int j = 0; j < 26; j++) {
              char currentSelect = 'a' + j;
              if (currentSelect != beforeChar && currentSelect != end) {
                s[i] = currentSelect;
                break;
              }
            }
          } else {
            // differnent than before
            if (s[i - 1] != 'z') {
              s[i] = s[i - 1] + 1;
            } else {
              s[i] = 'a';
            }
          }
        }
        before = s[startIndex];
        questionCount = 0;
        beforeHaveQuestion = false;
      } else {
        beforeHaveQuestion = true;
        questionCount++;
      }
      startIndex++;
    }
    s.pop_back();
    return s;
  }
};

int main() {
  Solution solve;
  string test = "j?qg??b";
  string res = solve.modifyString(test);
  return 0;
}