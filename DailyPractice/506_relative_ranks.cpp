#include <string>
#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
 public:
  vector<string> findRelativeRanks(vector<int>& score) {
    vector<int> copyScores = score;
    sort(score.begin(), score.end());
    reverse(score.begin(), score.end());
    unordered_map<int, string> map;
    vector<string> winners = {"Gold Medal", "Silver Medal", "BronzeMedal"};
    for (int i = 0; i < score.size(); i++) {
      if (i < 3) {
        map[score[i]] = winners[i];
      } else {
        map[score[i]] = to_string(i + 1);
      }
    }
    vector<string> res;
    res.reserve(score.size());
    for (auto copyScore : copyScores) {
      res.emplace_back(map[copyScore]);
    }
    return res;
  }
};