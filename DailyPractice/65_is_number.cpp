#include <string>
#include <unordered_set>
using namespace std;
class Solution {
 private:
  unordered_set<char> validateCharacter;
  int eIndex;
 public:
  bool isNumber(string s) {
    // e index default to -1.
    eIndex = -1;
    validateCharacter = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'e', 'E', '.'};
    for (int i = 0; i < s.size(); i++) {
      // Check invalidate character
    }
  }

  /// Check if character is valiadte.
  bool characterIsValidate(char current) {
    
  }

  /// If s is integer.
  bool isInteger(string s) {

  }

  /// If s is double.
  bool isDouble(string s) {

  }
};