#include <vector>
using namespace std;
class Solution {
 public:
  bool isBoomerang(vector<vector<int>>& points) {
    if (points.size() != 3) {
      return false;
    }
    // check first != second
    if (points[0][0] == points[1][0] && points[0][1] == points[1][1]) {
      return false;
    }
    if (points[0][0] == points[1][0]) {
      return !(points[2][0] == points[0][0]);
    }
    // check third not on the same line
    double a = 0;
    double b = points[0][1];
    if (points[1][0] - points[0][0] != 0) {
      a = double(points[1][1] - points[0][1]) /
          double(points[1][0] - points[0][0]);
      b = double(points[0][1] * points[1][0] - points[0][0] * points[1][1]) /
          double(points[1][0] - points[0][0]);
    }
    if (abs((double)(points[2][0] * a + b) - double(points[2][1])) <= 0.00001) {
      return false;
    }
    return true;
  }
};

int main() {
  Solution solve;
  vector<vector<int>> test = {{31, 86}, {25, 34}, {31, 86}};
  auto res = solve.isBoomerang(test);
  return 0;
}