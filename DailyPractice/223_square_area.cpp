#include <vector>
using namespace std;
class Solution {
 public:
  int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
    vector<vector<int>> squares = {{ax1, ay1, ax2, ay2}, {bx1, by1, bx2, by2}};
    sort(squares.begin(), squares.end());
    int cross = 0;
    int leftArea = (squares[0][3] - squares[0][1]) * (squares[0][2] - squares[0][0]);
    int rightArea = (squares[1][3] - squares[1][1]) * (squares[1][2] - squares[1][0]);
    vector<int> left = squares[0];
    vector<int> right = squares[1];
    if (right[0] >= left[0] && right[0] <= left[2]) {
      // x cross
      vector<vector<int>> height = {{ay1, ay2}, {by1, by2}};
      sort(height.begin(), height.end());
      vector<int> lower = height[0];
      vector<int> higher = height[1];
      if (higher[0] <= lower[1]) {
        int height = min(lower[1], higher[1]) - higher[0];
        int width = min(left[2], right[2]) - right[0];
        cross = height * width;
      }
    }
    return leftArea + rightArea - cross;
  }
};

int main() {
  Solution solve;
  int area = solve.computeArea(-2, -2, 2, 2, -2, -2, 2, 2);
  return 0;
}