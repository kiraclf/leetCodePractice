#include <vector>
#include <string>
using namespace std;
class Solution {
 public:
  bool checkValidString(string s) {
    vector<char> stack;
    int startIndex = 0;
    while (startIndex < s.size()) {
      char current = s[startIndex];
      if (current == '(') {
        stack.push_back(current);
      } else if (current == '*') {
        stack.push_back(current);
      } else {
        bool haveLeft = false;
        int backIndex = stack.size() - 1;
        while (backIndex >= 0) {
          if (stack[backIndex] == '(') {
            stack.erase(stack.begin()+=backIndex);
            haveLeft = true;
            break;
          }
        }
        if (!haveLeft) {
          int backIndex = stack.size() - 1;
          while (backIndex >= 0) {
            if (stack[backIndex] == '*') {
              stack.erase(stack.begin() += backIndex);
              haveLeft = true;
              break;
            }
          }
        }
        if (!haveLeft) {
          return false;
        }
      }
      startIndex++;
    }
    if (stack.size() == 0) {
      return true;
    }
    int endIndex = stack.size() - 1;
    while (endIndex >= 0) {
      if (stack[endIndex] == '(') {
        return false;
      } else {
        
      }
    }
    return true;
  }
};