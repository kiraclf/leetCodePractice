#include <set>
#include <vector>
using namespace std;
class Solution {
 public:
  bool isEscapePossible(vector<vector<int>>& blocked, vector<int>& source,
                        vector<int>& target) {
    // find enclosing rect from blocked.
    unordered_set<pair<int, int>> pointsSet;
    for (auto blockPoint : blocked) {
      pointsSet.insert(pair<int, int>(blockPoint[0], blockPoint[1]));
    }
    // x, y, w, h
    vector<vector<int>> blockedRects;
    for (auto blockPoint : blocked) {
      rectExist(blockPoint[0], blockPoint[1], blockedRects, pointsSet);
    }
    // check if blocked and target in the same block area.
    for (auto blockedRect : blockedRects) {
      bool targetInRect = pointInside(blockedRect, target);
      bool sourceInRect = pointInside(blockedRect, source);
      if (targetInRect != sourceInRect) {
        return false;
      }
    }
    return true;
  }

  bool pointInside(vector<int> rect, vector<int> point) {
    if (point[0] > rect[0] && point[0] < rect[0] + rect[2] &&
        point[1] > rect[1] && point[1] < rect[1] + rect[3]) {
      return true;
    }
    return false;
  }

  void rectExist(int x, int y, vector<vector<int>>& blockedRect,
                 unordered_set<pair<int, int>>& blocked) {}

  bool rectExist(int x, int y, int width, int height,
                 unordered_set<pair<int, int>>& blocked) {
    // Top
    if (y != 0) {
      for (int i = x; i <= x - 1 + width; i++) {
        pair<int, int> point = {i, y};
        if (blocked.find(point) == blocked.end()) {
          return false;
        }
      }
    }
    // Bottom
    if ((y + height) != 1000000 - 1) {
        }
    // Left
    // Right
    return true;
  }
};