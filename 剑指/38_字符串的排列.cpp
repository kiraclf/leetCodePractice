#include <string>
#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
 public:
  vector<string> permutation(string s) {
    // Prepare cache
    unordered_map<char, int> cache;
    for (int i = 0; i < s.size(); i++) {
      cache[s[i]] += 1;
    }
    // Result
    vector<string> result;
    // Dfs
    dfs(cache, "", s.size(), result);
    return result;
  }

  void dfs(unordered_map<char, int> &cache, string current, int targetSize, vector<string> &result) {
    if (current.size() == targetSize) {
      result.push_back(current);
      return;
    }
    for (auto pair : cache) {
      if (pair.second != 0) {
        current += pair.first;
        cache[pair.first] -= 1;
        dfs(cache, current, targetSize, result);
        cache[pair.first] += 1;
        current.pop_back();
      }
    }
  }
};

int main() {
  Solution solve;
  vector<string> result = solve.permutation("abc");
  return 0;
}