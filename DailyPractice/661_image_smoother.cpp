#include <vector>
using namespace std;
class Solution {
 public:
  vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
    vector<vector<int>> res = img;
    vector<vector<int>> moves = {{0, 0}, {-1, 0},  {1, 0},  {0, 1}, {0, -1},
                                 {1, 1}, {-1, -1}, {1, -1}, {-1, 1}};
    for (int i = 0; i < img.size(); ++i) {
      for (int j = 0; j < img[i].size(); ++j) {
        int sum = 0;
        int count = 0;
        for (auto move : moves) {
          int x = i + move[0];
          int y = j + move[1];
          if (x >= 0 && x < img.size() && y >= 0 && y < img[0].size()) {
            sum += img[x][y];
            count++;
          }
        }
        res[i][j] = sum / count;
      }
    }
    return res;
  }
};