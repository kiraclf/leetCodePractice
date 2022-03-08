#include <string>
#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
 public:
  vector<int> findAnagrams(string s, string p) {
    int sSize = s.size();
    int pSize = p.size();
    vector<int> res;
    if (sSize < pSize) {
      return res;
    }
    vector<int> patternArray(26, 0);
    for (auto character : p) {
      patternArray[character - 'a'] += 1;
    }
    vector<int> searchArray(26, 0);
    for (int i = 0; i < pSize - 1; i++) {
      searchArray[s[i] - 'a'] += 1;
    }
    for (int i = pSize - 1; i < sSize; i++) {
      if (i - pSize >= 0) {
        searchArray[s[i - pSize] - 'a'] -= 1;
      }
      searchArray[s[i] - 'a'] += 1;
      if (vectorEqual(searchArray, patternArray)) {
        res.push_back(i - (pSize - 1));
      }
    }
    return res;
  }

  bool vectorEqual(vector<int>& list1, vector<int>& list2) {
    for (int i = 0; i < list1.size(); i++) {
      if (list1[i] != list2[i]) {
        return false;
      }
    }
    return true;
  }
};

int main() {
  Solution solve;
  string test = "cbaebabacd";
  string pattern = "abc";
  auto res = solve.findAnagrams(test, pattern);
  return 0;
}