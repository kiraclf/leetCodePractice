#include <string>
#include <unordered_map>
#include <map>
using namespace std;
class Solution {
 public:
  string frequencySort(string s) {
    unordered_map<char, int> charMap;
    for (auto  character : s) {
      charMap[character] += 1;
    }
    map<int, string> countMap;
    for (auto character : charMap) {
      string charString = countMap[character.second];
      charString.push_back(to_string(character.first));
    }
    string result = "";
    for (auto countPair : countMap) {
      int count = countPair.first;
      for (auto character : countPair.second) {
        for (int i = 0; i < count; i++) {
          result.push_back(character);
        }
      }
    }
    return result;
  }
};

int main() {
  Solution solve;
  string result = solve.frequencySort("tree");
  return 0;
}