#include <string>
#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
 public:
  string findLongestWord(string s, vector<string>& dictionary) {
    // Create cache map
    unordered_map<char, vector<int>> charCache;
    for (int i = 0; i < s.size(); i++) {
      charCache[s[i]].push_back(i);
    }
    string ans = "";
    // Search
    for (auto s : dictionary) {
      if (canTransform(s, charCache)) {
        ans = updateString(s, ans);
      }
    }
    return ans;
  }

  string updateString(string oldString, string newString) {
    if (oldString.size() > newString.size()) {
      return oldString;
    } else if (oldString.size() < newString.size()) {
      return newString;
    } else {
      for (int i = 0; i < oldString.size(); i++) {
        if (oldString[i] < newString[i]) {
          return oldString;
        } else if (oldString[i] > newString[i]) {
          return newString;
        }
      }
      return oldString;
    }
  }

  bool canTransform(string s, unordered_map<char, vector<int>>& cache) {
    // find char exist
    vector<int> validate;
    for (auto character : s) {
      if (cache.find(character) == cache.end()) {
        return false;
      }
      vector<int> currentIndex = cache[character];
      if (validate.size() == 0) {
        validate.push_back(currentIndex[0]);
      } else {
        int before = validate[validate.size() - 1];
        bool exist = false;
        for (auto index : currentIndex) {
          if (index <= before) {
            continue;
          } else {
            validate.push_back(index);
            exist = true;
            break;
          } 
        }
        if (!exist) {
          return false;
        }
      }
    }
    return true;
  }
};

int main() {
  Solution solve;
  string test = "abcde";
  vector<string> dict = {"abe", "abc"};
  string res = solve.findLongestWord(test, dict);
  return 0;
}