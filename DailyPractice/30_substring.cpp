#include <string>
#include <vector>
using namespace std;
class Solution {
 public:
  vector<int> findSubstring(string s, vector<string> &words) {
    // all words count
    vector<int> ansList(26, 0);
    int totalCount = 0;
    for (auto word : words) {
      for (auto character : word) {
        ansList[character - 'a'] += 1;
        totalCount += 1;
      }
    }
    if (s.size() < totalCount) {
      return {};
    }
    // first
    vector<vector<int>> sList;
    for (int i = 0; i < totalCount; i++) {
      if (i == 0) {
        vector<int> charList(26, 0);
        charList[s[i] - 'a'] += 1;
        sList.push_back(charList);
      } else {
        vector<int> before = sList[i - 1];
        before[s[i] - 'a'] += 1;
        sList.push_back(before);
      }
    }
    // iterate
    vector<int> res;
    if (compare(sList[totalCount - 1], ansList)) {
      res.push_back(0);
    }
    vector<int> toCompare(26, 0);
    for (int i = totalCount; i < s.size(); i++) {
      auto before = sList[totalCount - 1];
      before[s[i] - 'a'] += 1;
      sList.push_back(before);
      for (int j = 0; j < 26; j++) {
        toCompare[j] = before[j] - sList[0][j];
      }
      if (compare(toCompare, ansList)) {
        res.push_back(i - totalCount + 1);
      }
      sList.erase(sList.begin());
    }
    return res;
  }

  bool compare(vector<int> &list1, vector<int> &list2) {
    for (int i = 0; i < 26; i++) {
      if (list1[i] != list2[i]) {
        return false;
      }
    }
    return true;
  }
};

int main() {
  Solution solve;
  string s = "barfoofoobarthefoobarman";
  vector<string> test = {"bar", "foo", "the"};
  auto res = solve.findSubstring(s, test);
  return 0;
}