#include <string>
#include <vector>
using namespace std;
class Solution {
 public:
  string convert(string s, int numRows) {
    if (numRows == 1) {
      return s;
    }
    // create new string vec
    vector<char> singleLine;
    vector<vector<char>> zigZag(numRows, singleLine);
    // process
    for (int i = 0; i < s.size(); i++) {
      int lineIndex = i % (numRows - 1);
      int lineCount = i / (numRows - 1);
      if (lineCount % 2 == 0) {
        // down
        zigZag[lineIndex].push_back(s[i]);
      } else {
        // up
        zigZag[numRows - 1 - lineIndex].push_back(s[i]);
      }
    }
    // generate ans
    string ans = "";
    for (int i = 0; i < zigZag.size(); i++) {
      for (int j = 0; j < zigZag[i].size(); j++) {
        ans += zigZag[i][j];
      }
    }
    return ans;
  }
};

int main() {
  Solution solve;
  string test = "A";
  int rows = 1;
  string ans = solve.convert(test, rows);
  return 0;
}