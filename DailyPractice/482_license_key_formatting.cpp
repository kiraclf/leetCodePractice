#include <string>
#include <vector>
using namespace std;

class Solution {
 public:
  string licenseKeyFormatting(string s, int k) {
    vector<string> res;
    int endIndex = s.length() - 1;
    int currentCount = 0;
    string current = "";
    while (endIndex >= 0) {
      char character = s[endIndex];
      if (character == '-') {
        endIndex--;
        continue;
      }
      if ( character >= 'a' && character <= 'z') {
        character = character + 'A' - 'a';
      }
      current.insert(current.begin(), character);
      currentCount++;
      if (currentCount == k) {
        res.push_back(current);
        currentCount = 0;
        current = "";
      }
      endIndex--;
    }
    if (current.size() != 0) {
      res.push_back(current);
    }
    reverse(res.begin(), res.end());
    string result = "";
    for (int i = 0; i < res.size(); i++) {
      if (i == 0) {
        result += res[i];
      } else {
        result += "-" + res[i];
      }
    }
    return result;
  }
};

int main() {
  Solution solve;
  string res = solve.licenseKeyFormatting("2-5g-3-J", 2);
  return 0;
}