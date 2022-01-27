#include <string>
using namespace std;
class Solution {
 public:
  int countValidWords(string sentence) {
    int validateCount = 0;
    int startIndex = 0;
    string current = "";
    while (startIndex < sentence.size()) {
      if (sentence[startIndex] == ' ') {
        if (current.size() > 0) {
          if (stringIsValidate(current)) {
            validateCount++;
          }
        }
        current = "";
      } else {
        current += sentence[startIndex];
      }
      startIndex++;
    }
    if (current.size() != 0 && stringIsValidate(current)) {
      validateCount++;
    }
    return validateCount;
  }

  bool stringIsValidate(string text) {
    int lineCount = 0;
    int dotCount = 0;
    for (int i = 0; i < text.size(); i++) {
      if (text[i] >= '0' && text[i] <= '9') {
        return false;
      }
      if (text[i] == '-') {
        if (i == 0 || i == text.size() - 1) {
          return false;
        } else if (text[i - 1] < 'a' || text[i - 1] > 'z' ||
                   text[i + 1] < 'a' || text[i + 1] > 'z') {
          return false;
        } else {
          lineCount++;
          if (lineCount > 1) {
            return false;
          }
        }
      }
      if (text[i] == '!' || text[i] == '.' || text[i] == ',') {
        dotCount++;
        if (dotCount > 1 || i != text.size() - 1) {
          return false;
        }
      }
    }
    return true;
  }
};

int main() {
  Solution solve;
  string test = "f    6c x2";
  int count = solve.countValidWords(test);
  return 0;
}