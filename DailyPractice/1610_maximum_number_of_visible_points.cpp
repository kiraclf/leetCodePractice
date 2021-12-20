#include <math.h>

#include <cmath>
#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
 public:
  int visiblePoints(vector<vector<int>>& points, int angle,
                    vector<int>& location) {
    // 统计 0 点的坐标
    int zeroCount = 0;
    // 统计角度
    vector<double> lineVec;
    // 变化坐标,以自己为中心
    for (int i = 0; i < points.size(); i++) {
      points[i][0] -= location[0];
      points[i][1] -= location[1];
      if (points[i][0] == 0 && points[i][1] == 0) {
        zeroCount += 1;
        continue;
      }
      double radius = 0;
      if (points[i][0] == 0 && points[i][1] > 0) {
        radius = 90.0;
      } else if (points[i][0] == 0 && points[i][1] < 0) {
        radius = 270.0;
      } else {
        radius = atan2(points[i][1], points[i][0]) / (2 * M_PI) * 360.0;
      }
      lineVec.push_back(radius);
    }
    // 排序
    sort(lineVec.begin(), lineVec.end());
    int lineSize = lineVec.size();
    for (int i = 0; i < lineSize; i++) {
      lineVec.push_back(lineVec[i] + 360);
    }
    int currentLineSize = lineVec.size();
    int maxCount = 0;
    int startIndex = 0;
    int endIndex = 0;
    while (startIndex < lineVec.size()) {
      while (endIndex < lineVec.size() &&
             lineVec[endIndex] - lineVec[startIndex] <= angle) {
        endIndex++;
      }
      maxCount = max(maxCount, endIndex - startIndex);
      startIndex++;
    }
    return maxCount + zeroCount;
  }
};

int main() {
  Solution solve;
  vector<vector<int>> points = {{1, 0}, {2, 1}};
  int angle = 13;
  vector<int> location = {1, 1};
  int max = solve.visiblePoints(points, angle, location);
  return 0;
}