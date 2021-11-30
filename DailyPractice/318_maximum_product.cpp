#include <string>
#include <vector>
using namespace std;
class Solution {
 public:
  int maxProduct(vector<string>& words) {
    vector<int> charExist(words.size(), 0);
    for (int i = 0; i < words.size(); i++) {
      string currentStr = words[i];
      int value = 0;
      for (auto character : currentStr) {
        int index = character - 'a';
        value = value | (1 << index);
      }
      charExist[i] = value;
    }
    int maxRes = 0;
    for (int i = 0; i < words.size(); i++) {
      for (int j = i + 1; j < words.size(); j++) {
        int setA = charExist[i];
        int setB = charExist[j];
        bool overlap = false;
        for (int i = 0; i < 26; i++) {
          if ((((setA >> i) & 1) == 1) && ((((setB >> i) & 1) == 1))) {
            overlap = true;
            break;
          }
        }
        if (!overlap) {
          maxRes = max(maxRes, (int)words[i].size() * (int)words[j].size());
        }
      }
    }
    return maxRes;
  }
};

int main() {
  Solution solve;
  vector<string> test = {"a", "ab", "abc", "d", "cd", "bcd", "abcd"};
  int result = solve.maxProduct(test);
  return 0;
}