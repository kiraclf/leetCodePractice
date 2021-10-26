#include <string>
using namespace std;
class Solution {
 public:
  string countAndSay(int n) {
    string res = "1";
    if (n == 1) {
      return res;
    }
    for (int i = 1; i < n; i++) {
      res = countAndSay(res);
    }
    return res;
  }

  string countAndSay(string s) {
    string res = "";
    char currentCharacter = s[s.size() - 1];
    int currentCount = 1;
    for (int i = s.size() - 2; i >= 0; i--) {
      char current = s[i];
      if (current == currentCharacter) {
        currentCount++;
      } else {
        // update result
        res.insert(0, countAndNumber(currentCharacter, currentCount));
        // update currentCharacter
        currentCharacter = current;
        currentCount = 1;
      }
    }
    res.insert(0, countAndNumber(currentCharacter, currentCount));
    return res;
  }

  string countAndNumber(char character, int count) {
    string res = "";
    res += to_string(count);
    res.push_back(character);
    return res;
  }
};

int main() {
  Solution solve;
  string res = solve.countAndSay(5);
  return 0;
}