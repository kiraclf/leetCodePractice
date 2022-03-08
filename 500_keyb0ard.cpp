#include <string>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
 private:
  vector<unordered_set<char>> sets;

 public:
  vector<string> findWords(vector<string>& words) {
    unordered_set<char> first = {'q', 'w', 'e', 'r', 't',
                                 'y', 'u', 'i', 'o', 'p'};
    unordered_set<char> second = {'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l'};
    unordered_set<char> third = {'z', 'x', 'c', 'v', 'b', 'n', 'm'};
    sets = {first, second, third};
    vector<string> ans;
    for (auto word : words) {
      int setIndex = -1;
      bool add = true;
      for (auto character : word) {
        for (int i = 0; i < sets.size(); i++) {
          if (sets[i].find(character) != sets[i].end()) {
            if (setIndex == -1) {
              setIndex = i;
            } else {
              if (setIndex != i) {
                add = false;
              }
            }
            break;
          }
        }
        if (!add) {
          break;
        }
      }
      if (add) {
        ans.push_back(word);
      }
    }
    return ans;
  }
};

int main() {
  Solution solve;
  vector<string> test = {"Hello", "Alaska", "Dad", "Peace"};
  vector<string> res = solve.findWords(test);
  return 0;
}