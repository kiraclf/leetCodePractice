#include <string>
#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
 public:
  vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string ,vector<string>> hashMap;
    for (auto str : strs) {
      string hashString = hashCharacterString(str);
      hashMap[hashString].push_back(str);
    }
    vector<vector<string>> res;
    for (auto hashPair : hashMap) {
      res.push_back(hashPair.second);
    }
    return res;
  }

  string hashCharacterString(string characters) {
    vector<int> characterCache(26, 0);
    for (auto character : characters) {
      int index = character - 'a';
      characterCache[index] += 1;
    }
    string res = "";
    for (auto characterC : characterCache) {
      if (characterC == 0) {
        res += '0';
      } else {
        res += to_string(characterC);
      }
    }
    return res;
  }
};

int main() {
  Solution solve;
  vector<string> test = {"eat", "tea", "tan", "ate", "nat", "bat"};
  vector<vector<string>> res = solve.groupAnagrams(test);
  return 0;
}