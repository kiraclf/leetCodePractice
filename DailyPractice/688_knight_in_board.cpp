#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
 private:
  int n;
  int k;
  unordered_map<int, vector<int>> pointInnerMap;

 public:
  double knightProbability(int n, int k, int row, int column) {
    if (k == 0) {
      return 1;
    }
    this->n = n;
    this->k = k;
    // save possible next points.
    this->pointInnerMap = {};
    int step = 1;
    vector<int> step1Points = possiblePoints(row * n + column);
    queue<int> nodes;
    for (auto step1Point : step1Points) {
      nodes.push(step1Point);
    }
    while (step <= k && nodes.size() > 0) {
      int nodesSize = nodes.size();
      while (nodesSize > 0) {
        nodesSize--;
        int currentKey = nodes.front();
        nodes.pop();
        vector<int> sibilings = possiblePoints(currentKey);
        for (auto sib : sibilings) {
          nodes.push(sib);
        }
      }
      step++;
    }
    if (nodes.size() == 0) {
      return 0;
    }
    double ans = nodes.size() / pow(8, k);
    return ans;
  }

  vector<int> possiblePoints(int key) {
    if (pointInnerMap.find(key) != pointInnerMap.end()) {
      return pointInnerMap[key];
    } else {
      vector<int> sibilings = {-11, -9, -7, -3, 3, 7, 9, 11};
      vector<int> possibleList;
      for (auto sibiling : sibilings) {
        int sibKey = key + sibiling;
        if (sibKey >= 0 && sibKey < n * n) {
          possibleList.push_back(sibKey);
        }
      }
      pointInnerMap[key] = possibleList;
      return possibleList;
    }
  }
};

int main() {
  Solution solve;
  double res = solve.knightProbability(3, 2, 0, 0);
  return 0;
}