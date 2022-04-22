#include <string>
using namespace std;
class Solution {
 public:
  string toGoatLatin(string sentence) {
    string ans;
    int index = 0;
    int stringIndex = 0;
    while (index < sentence.size()) {
      string current = "";
      bool startWithRound = false;
      while (index < sentence.size() && sentence[index] != ' ') {
        char currentChar = sentence[index];
        if (current == "" && (currentChar == 'a' || currentChar == 'e' ||
                              currentChar == 'o' || currentChar == 'u')) {
          startWithRound = true;
        }
        current += currentChar;
        index++;
      }
      if (startWithRound) {
        current += "ma";
      } else {
        char firstCharacter = current[0];
        current =
            (current.substr(1, current.size() - 1) + firstCharacter) + "ma";
      }
      for (int i = 0; i <= stringIndex; i++) {
        current += 'a';
      }
      current += ' ';
      ans += current;
      current = "";
      stringIndex++;
      index++;
    }
    ans.pop_back();
    return ans;
  }
};

int main() {
  Solution solve;
  string test = "I speak Goat Latin";
  auto res = solve.toGoatLatin(test);
  return 0;
}