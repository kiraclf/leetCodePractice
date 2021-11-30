#include <string>
#include <unordered_map>
#include <unordered_set>
using namespace std;
class Solution {
 public:
  string getHint(string secret, string guess) {
    int size = secret.size();
    unordered_map<char, int> charMap;
    unordered_set<int> visited;
    for (auto character : secret) {
      charMap[character] += 1;
    }
    // bulls count
    int bullCount = 0;
    for (int i = 0; i < size; i++) {
      if (secret[i] == guess[i]) {
        bullCount += 1;
        charMap[secret[i]] -= 1;
        visited.insert(i);
      }
    }
    // cows count
    int cowCount = 0;
    for (int i = 0; i < size; i++) {
      if (visited.find(i) != visited.end()) {
        continue;
      }
      char character = guess[i];
      if (charMap.find(character) != charMap.end()) {
        if (charMap[character] > 0) {
          cowCount++;
          charMap[character] -= 1;
        }
      }
    }
    return to_string(bullCount) + "A" + to_string(cowCount) + "B";
  }
};

int main() {
  Solution solve;
  string secert = "1";
  string guess = "0";
  string res = solve.getHint(secert, guess);
  return 0;
}