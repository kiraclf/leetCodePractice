#include <string>
#include <unordered_set>
#include <vector>
using namespace std;
class Solution {
 public:
  vector<int> diStringMatch(string s) {
    int possibleSmallest = 0;
    int possibleMax = s.size();
    vector<int> res;
    res.reserve(s.size() + 1);
    for (auto character : s) {
      if (character == 'I') {
        // less than after
        res.push_back(possibleSmallest);
        possibleSmallest++;
      } else {
        // bigger than after
        res.push_back(possibleMax);
        possibleMax--;
      }
    }
    res.push_back(possibleMax);
    return res;
  }
};