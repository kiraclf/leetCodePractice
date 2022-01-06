#include <vector>
using namespace std;
class Solution {
 public:
  vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
    if (original.size() != m * n) {
      return vector<vector<int>>{};
    }
    vector<int> row(n, 0);
    vector<vector<int>> res(m, row);
    for (int i = 0; i < original.size(); i++) {
      int rowIndex = i / n;
      int columnIndex = i % n;
      res[rowIndex][columnIndex] = original[i];
    }
    return res;
  }
};

int main() {
  vector<int> test = {1, 2, 3};
  Solution solve;
  auto res = solve.construct2DArray(test, 1, 3);
  return 0;
}