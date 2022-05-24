#include <string>
#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
 public:
  bool isAlienSorted(vector<string>& words, string order) {
    if (words.size() <= 1) {
      return true;
    }
    unordered_map<char, int> charOrderMap;
    for (int i = 0; i < order.size(); i++) {
      charOrderMap[order[i]] = i;
    }
    for (int i = 1; i < words.size(); i++) {
      if (!beforeLessThanCurrent(words[i - 1], words[i], charOrderMap)) {
        return false;
      }
    }
    return true;
  }

  bool beforeLessThanCurrent(string& before, string& current,
                             unordered_map<char, int>& orderMap) {
    for (int i = 0; i < before.size(); i++) {
      if (i < current.size()) {
        if (orderMap[before[i]] > orderMap[current[i]]) {
          return false;
        } else if (orderMap[before[i]] < orderMap[current[i]]) {
          return true;
        }
      } else {
        return false;
      }
    }
    return true;
  }
};

int main() {
  Solution solve;
  vector<string> words = {"word", "world", "row"};
  string order = "worldabcefghijkmnpqstuvxyz";
  bool res = solve.isAlienSorted(words, order);
  return 0;
}