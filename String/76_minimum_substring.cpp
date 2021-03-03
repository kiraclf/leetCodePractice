#include "string"
#include "unordered_map"
#include "set"
using namespace std;
/*
--- 题目描述
给你一个字符串 s 、一个字符串 t 。返回 s 中涵盖 t 所有字符的最小子串。如果 s
中不存在涵盖 t 所有字符的子串，则返回空字符串 "" 。
注意：如果 s 中存在这样的子串，我们保证它是唯一的答案。
* 1 <= s.length, t.length <= 105
* s 和 t 由英文字母组成
--- 思路
* 最小子串一定是以t中的某个字符开头和结尾的
*/
class Solution {
 public:
  string minWindow(string s, string t) {
    unordered_map<char, int> charMap, currentMap;
    // init charMap
    for (auto character: t) {
      charMap[character]++;
    }
    // sliding window
    int start = 0, end = 0;
    int currentLength = INT32_MAX;
    string minString = "";
    while (end < int(s.size())) {
      if (charMap.find(s[end]) != charMap.end()) {
        currentMap[s[end]]++;
      }
      if (characterMapValidate(charMap, currentMap)) {
        while (start <= end) {
          if (charMap.find(s[start]) == charMap.end()) {
            start++;
          } else {
            if (end - start + 1 < currentLength) {
              minString = s.substr(start, end - start + 1);
            }
            currentMap[s[start]]--;
            if (characterMapValidate(charMap, currentMap)) {
              start++;
            } else {
              start++;
              break;
            }
          }
        }
      }
      end++;
    }
    return minString;
  }

  bool characterMapValidate(unordered_map<char, int>& cacheMap, unordered_map<char, int>& currentMap) {
    for (auto character: cacheMap) {
      if (character.second > currentMap[character.first]) {
        return false;
      }
    }
    return true;
  }
};

int main() {
  Solution solve;
  string result = solve.minWindow("ADOBECODEBANC", "ABC");
  return 0;
}