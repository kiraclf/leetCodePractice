#include <unordered_set>
#include <vector>
using namespace std;
class Solution {
 public:
  bool escapeGhosts(vector<vector<int>>& ghosts, vector<int>& target) {
    unordered_set<pair<int, int>> possiblePoint;
    unordered_set<pair<int, int>> jamPoint;
    possiblePoint.insert(pair<int, int>(0, 0));
    for (auto ghost : ghosts) {
      jamPoint.insert(pair<int, int>(ghost[0], ghost[1]));
    }
    while (possiblePoint.size() != 0) {
      if (possiblePoint.find(pair<int, int>(target[0], target[1])) !=
          possiblePoint.end()) {
        return true;
      } else if (jamPoint.find(pair<int, int>(target[0], target[1])) !=
                 jamPoint.end()) {
        return false;
      } else {
        moveJamPoint(jamPoint);
        unordered_set<pair<int, int>> nexSet;
        for (auto point : possiblePoint) {
          if (jamPoint.find(point) != jamPoint.end()) {
            possiblePoint.erase(point);
          } else {
            auto nextPoints = movePoint(point);
            for (auto next : nextPoints) {
              if (jamPoint.find(next) != jamPoint.end()) {
                nexSet.insert(next);
              }
            }
            possiblePoint.erase(point);
          }
        }
        for (auto nex : nexSet) {
          possiblePoint.insert(nex);
        }
      }
    }
    return false;
  }

  void moveJamPoint(unordered_set<pair<int, int>>& jamPoints) {
    vector<pair<int, int>> toAddPoint;
    for (auto point : jamPoints) {
      auto nextPoint = movePoint(point);
      for (auto next : nextPoint) {
        toAddPoint.push_back(next);
      }
    }
    for (auto next : toAddPoint) {
      jamPoints.insert(next);
    }
  }

  vector<pair<int, int>> movePoint(pair<int, int> point) {
    int x = point.first;
    int y = point.second;
    vector<pair<int, int>> res;
    // 上
    if (y < 10000) {
      res.push_back(pair<int, int>(x, y + 1));
    }
    // 下
    if (y > -10000) {
      res.push_back(pair<int, int>(x, y - 1));
    }
    // 左
    if (x > -10000) {
      res.push_back(pair<int, int>(x - 1, y));
    }
    // 右
    if (x < 10000) {
      res.push_back(pair<int, int>(x + 1, y));
    }
    return res;
  }
};

int main() {
  Solution solve;
  vector<vector<int>> ghosts = {{1,0}};
  vector<int> target = {2, 0};
  bool result = solve.escapeGhosts(ghosts, target);
  return 0;
}