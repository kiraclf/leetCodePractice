#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;
class Solution {
 public:
  vector<int> luckyNumbers(vector<vector<int>>& matrix) {
    unordered_set<int> set;
    vector<int> minIndex;
    for (int row = 0; row < matrix.size(); ++row) {
      minIndex.clear();
      int minValue = INT_MAX;
      for (int column = 0; column < matrix[row].size(); ++column) {
        if (matrix[row][column] < minValue) {
          minIndex.clear();
          minValue = matrix[row][column];
          minIndex.push_back(column);
        } else if (matrix[row][column] == minValue) {
          minIndex.push_back(column);
        }
      }
      for (auto index : minIndex) {
        bool isBiggest = true;
        for (int checkRow = 0; checkRow < matrix.size(); checkRow++) {
          if (matrix[row][index] < matrix[checkRow][index]) {
            isBiggest = false;
            break;
          }
        }
        if (isBiggest) {
          set.insert(matrix[row][index]);
        }
      }
    }
    vector<int> res;
    for (auto result : set) {
      res.push_back(result);
    }
    return res;
  }
};

int main() {
  Solution solve;
  vector<vector<int>> matrix = {{3, 7, 8}, {9, 11, 13}, {15, 16, 17}};
  vector<int> res = solve.luckyNumbers(matrix);
  return 0;
}