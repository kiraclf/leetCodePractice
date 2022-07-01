#include <vector>
using namespace std;
class Solution {
 public:
  vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
    int totalCount = mat.size() * mat[0].size();
    vector<int> res(totalCount, 0);
    pair<int, int> current = {0, 0};
    int currentCount = 0;
    bool up = true;
    while (currentCount < totalCount) {
      res[currentCount] = mat[current.first][current.second];
      currentCount++;
      if (up) {
        pair<int, int> next = {current.first - 1, current.second + 1};
        if (next.first < 0 || next.second >= mat[0].size()) {
          // invalidate
          up = !up;
          if (next.second == mat[0].size()) {
            next.first = current.first + 1;
            next.second = current.second;
          } else {
            next.first = current.first;
            next.second = current.second + 1;
          }
        }
        current = next;
      } else {
        pair<int, int> next = {current.first + 1, current.second - 1};
        if (next.second < 0 || next.first >= mat.size()) {
          // invalidate
          up = !up;
          if (next.second == -1 && next.first != mat.size()) {
            next.first = current.first + 1;
            next.second = current.second;
          } else {
            next.first = current.first;
            next.second = current.second + 1;
          }
        }
        current = next;
      }
    }
    return res;
  }
};

int main() {
  Solution solve;
  vector<vector<int>> test = {{1,2,3}, {4,5,6}, {7,8,9}};
  auto res = solve.findDiagonalOrder(test);
  return 0;
}