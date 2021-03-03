#include <vector>
using namespace std;
class Solution {
 public:
  vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
    for (int i = 0; i < A.size(); i++) {
      flipVector(A[i]);
    }
    return A;
  }

  void flipVector(vector<int> &line) {
    int startIndex = 0;
    int endIndex = line.size() - 1;
    while (startIndex <= endIndex) {
      // change value
      line[startIndex] = line[startIndex] == 0 ? 1 : 0;
      if (startIndex != endIndex) {
        line[endIndex] = line[endIndex] == 0 ? 1 : 0;
      }
      // reverse
      int temp = line[startIndex];
      line[startIndex] = line[endIndex];
      line[endIndex] = temp;
      startIndex++;
      endIndex--;
    } 
  }
};