#include <vector>
#include <unordered_map>
#include <string>
using namespace std;
class Solution {
 public:
  vector<string> findRepeatedDnaSequences(string s) {
    unordered_map<string, int> cache;
    for (int i = 0; i <= ((int)s.size() - 10); i++) {
      string subString = s.substr(i, 10);
      cache[subString] += 1;
    }
    vector<string> res;
    for (auto pair : cache) {
      if (pair.second > 1) {
        res.push_back(pair.first);
      }
    }
    return res;
  }
};

int main() {
  Solution solve;
  vector<string> res= solve.findRepeatedDnaSequences("A");
  return 0;
}