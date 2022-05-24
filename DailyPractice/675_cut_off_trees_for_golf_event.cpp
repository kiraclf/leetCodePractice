#include <queue>
#include <unordered_set>
#include <vector>
using namespace std;
bool myLess(pair<int, int> a, pair<int, int> b) { return a.first < b.first; }
class Solution {
 private:
  vector<vector<int>> forest;
  // value, hash
  vector<pair<int, int>> toCutTrees;
  vector<vector<int>> steps = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

 public:
  int cutOffTree(vector<vector<int>>& forest) {
    this->forest = forest;
    this->toCutTrees = {};
    for (int x = 0; x < forest.size(); x++) {
      for (int y = 0; y < forest[x].size(); y++) {
        if (forest[x][y] > 1) {
          toCutTrees.push_back(pair<int, int>(forest[x][y], hash(x, y)));
        }
      }
    }
    sort(toCutTrees.begin(), toCutTrees.end(), myLess);
    int ans = 0;
    int currentPosistion = 0;
    for (int i = 0; i < toCutTrees.size(); i++) {
      int step = minimunStepToPoint(currentPosistion, toCutTrees[i].second);
      if (step == -1) {
        return -1;
      }
      ans += step;
      currentPosistion = toCutTrees[i].second;
    }
    return ans;
  }

  int minimunStepToPoint(int start, int end) {
    if (start == end) {
      return 0;
    }
    auto startPoint = dehash(start);
    auto endPoint = dehash(end);
    queue<pair<int, int>> points;
    vector<int> visitedLine(50, 0);
    vector<vector<int>> visited(50, visitedLine);
    points.push(startPoint);
    auto point = dehash(start);
    visited[point.first][point.second] = 1;
    int ans = 0;
    while (points.size() > 0) {
      int size = points.size();
      ans++;
      while (size > 0) {
        auto currentPoint = points.front();
        points.pop();
        size--;
        for (auto step : steps) {
          int x = currentPoint.first + step[0];
          int y = currentPoint.second + step[1];
          if (x >= 0 && x < forest.size() && y >= 0 && y < forest[0].size() &&
              forest[x][y] != 0 && visited[x][y] != 1) {
            points.push(pair<int, int>(x, y));
            visited[x][y] = 1;
            if (hash(x, y) == end) {
              return ans;
            }
          }
        }
      }
    }
    return -1;
  }

  int hash(int x, int y) { return x * 100 + y; }

  pair<int, int> dehash(int value) {
    int x = value / 100;
    int y = value - x * 100;
    return pair<int, int>(x, y);
  }
};

int main() {
  Solution solve;
  vector<vector<int>> forest = {{2, 3, 4}, {0, 0, 5}, {8, 7, 6}};
  int step = solve.cutOffTree(forest);
  return 0;
}