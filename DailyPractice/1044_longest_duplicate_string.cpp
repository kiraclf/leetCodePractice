#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Solution {
 public:
  string longestDupSubstring(string s) {
    int currentPossibleCount = 0;
    string res = "";
    for (int i = 1; i < s.size(); i++) {
      int possibleCount = currentPossibleCount + 1;
      cout << "possible count: " << possibleCount << endl;
      string pattern = s.substr(i + 1 - possibleCount, possibleCount);
      string toMatch = s.substr(0, i);
      if (kmpContains(toMatch, pattern)) {
        currentPossibleCount += 1;
        res = pattern;
      }
    }
    return res;
  }

 public:
  bool kmpContains(string s, string pattern) {
    vector<int> prefixTable = prefixeTable(pattern);
    // s[i] pattern[j]
    int i = 0;
    int j = 0;
    while (i < s.size()) {
      if (j == pattern.size() - 1 && s[i] == pattern[j]) {
        // contains substring
        return true;
      }
      if (s[i] == pattern[j]) {
        // current match
        i++;
        j++;
      } else {
        j = prefixTable[j];
        if (j == -1) {
          // 头部
          i++;
          j = 0;
        }
      }
    }
    return false;
  }

 private:
  vector<int> prefixeTable(string pattern) {
    vector<int> prefix(pattern.size(), 0);
    int len = 0;
    int endIndex = 1;
    while (endIndex < prefix.size()) {
      if (pattern[endIndex] == pattern[len]) {
        endIndex++;
        len++;
        prefix[endIndex] = len;
      } else {
        if (len == 0) {
          endIndex++;
        } else if (len > 0) {
          len = prefix[len - 1];
        }
      }
    }
    // transform current table
    for (int i = prefix.size() - 1; i >= 1; i--) {
      prefix[i] = prefix[i - 1];
    }
    prefix[0] = -1;
    return prefix;
  }
};

int main() {
  Solution solve;
  string s = "banana";
  string pattern = "ana";
  string result = solve.longestDupSubstring(s);
  return 0;
}