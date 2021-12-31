#include <string>
#include <vector>
using namespace std;
class Solution {
 public:
  vector<string> findOcurrences(string text, string first, string second) {
    text += ' ';
    vector<string> allStrings;
    int start = 0;
    for (int i = 0; i < text.size(); i++) {
      if (text[i] == ' ') {
        string current = text.substr(start, i - start);
        allStrings.push_back(current);
        start = i + 1;
      }
    }
    vector<string> res;
    for (int i = 0; i < allStrings.size(); i++) {
      if (allStrings[i] == first && i < allStrings.size() - 2 &&
          allStrings[i + 1] == second) {
        res.push_back(allStrings[i + 2]);
      }
    }
    return res;
  }
};

int main() {
  Solution solve;
  string text = "we will we will rock you";
  string first = "we";
  string second = "will";
  vector<string> res = solve.findOcurrences(text, first, second);
  return 0;
}