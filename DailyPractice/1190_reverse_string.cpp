#include <string>
#include <vector>
using namespace std;
class Solution {
 public:
  string reverseParentheses(string s) {
    vector<char> stack;
    vector<char> temp;
    for (int i = 0; i < s.size(); i++) {
      if (s[i] != ')') {
        stack.push_back(s[i]);
      } else {
        // pop back
        while (stack[stack.size() -1] != '(') {
          temp.push_back(stack[stack.size() -1]);
          stack.pop_back();
        }
        stack.pop_back();
        // insert reverse
        for (int i = 0; i < temp.size(); i++) {
          stack.push_back(temp[i]);
        }
        // clear
        temp.clear();
      }
    }
    string result = "";
    for (int i = 0; i < stack.size(); i++) {
      result += stack[i];
    }
    return result;
  }
};

int main() {
  Solution solve;
  string result = solve.reverseParentheses("(ed(et(oc))el)");
  return 0;
}