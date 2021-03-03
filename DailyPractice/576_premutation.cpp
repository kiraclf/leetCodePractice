#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution {
 public:
  bool checkInclusion(string s1, string s2) {
    if (s2.length() < s1.length()) {
      return false;
    }
    // init target cache map
    unordered_map<char, int> cacheMap;
    unordered_set<char> charSet;
    for (auto character : s1) {
      if (cacheMap.find(character) == cacheMap.end()) {
        cacheMap[character] = 1;
      } else {
        cacheMap[character] += 1;
      }
      charSet.insert(character);
    }
    // sliding
    int left = 0;
    while (left < s2.size() && cacheMap.find(s2[left]) == cacheMap.end()) {
      left++;
    }
    if (left == s2.size()) {
      return false;
    }
    int right = left;
    while (right < s2.size()) {
      if (cacheMap.find(s2[right]) != cacheMap.end()) {
        cacheMap[s2[right]]--;
        if (cacheMap[s2[right]] == 0) {
          cacheMap.erase(s2[right]);
        }
        if (cacheMap.size() == 0) {
          return true;
        }
        right++;
      } else {
        if (charSet.find(s2[right]) == charSet.end()) {
          while (left < right) {
          if (cacheMap.find(s2[left]) == cacheMap.end()) {
            cacheMap[s2[left]] = 1;
          } else {
            cacheMap[s2[left]] += 1;
          }
          left++;
        }
        left++;
        right++;
        } else {
          if (cacheMap.find(s2[left]) == cacheMap.end()) {
            cacheMap[s2[left]] = 1;
          } else {
            cacheMap[s2[left]] += 1;
          }
          left++;
        }
        
      }
    }
    return false;
  }
};


int main() {
  Solution solve;
  int result = solve.checkInclusion("adc", "dcda");
  return 0;
}
