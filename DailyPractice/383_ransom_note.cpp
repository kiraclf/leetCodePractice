#include <string>
#include <vector>
using namespace std;
class Solution {
 public:
  bool canConstruct(string ransomNote, string magazine) {
    vector<int> magazineMap(26, 0);
    for (auto character : magazine) {
      magazineMap[character - 'a'] += 1;
    }
    for (auto character : ransomNote) {
      int index = character - 'a';
      magazineMap[index] -= 1;
      if (magazineMap[index] < 0) {
        return false;
      }
    }
    return true;
  }
};