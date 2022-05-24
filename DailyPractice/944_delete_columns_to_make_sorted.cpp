#include <string>
#include <vector>
using namespace std;
class Solution {
 public:
  int minDeletionSize(vector<string>& strs) {
    int rowSize = strs.size();
    int columnSize = strs[0].size();
    int deleteCount = 0;
    for (int colum = 0; colum < columnSize; colum++) {
      char current = strs[0][colum];
      for (int row = 1; row < rowSize; row++) {
        char next = strs[row][colum];
        if (next < current) {
          deleteCount++;
          break;
        }
        current = next;
      }
    }
    return deleteCount;
  }
};

int main() {
  Solution solve;
  vector<string> test = {"zyx", "wvu", "tsr"};
  int ans = solve.minDeletionSize(test);
  return 0;
}