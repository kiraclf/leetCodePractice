#include <string>
#include <vector>
using namespace std;
class Solution {
 public:
  vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
    // nearest left candles index.
    vector<int> leftIndex(s.size(), -1);
    // nearset right candles index.
    vector<int> rightIndex(s.size(), -1);
    // number of plates
    vector<int> countOfPlates(s.size(), 0);
    // generate left and right
    int leftNearstCandleIndex = -1;
    int numberOfPlates = 0;
    for (int i = 0; i < s.size(); i++) {
      if (s[i] == '|') {
        leftNearstCandleIndex = i;
        countOfPlates[i] = numberOfPlates;
        leftIndex[i] = leftNearstCandleIndex;
      } else {
        leftIndex[i] = leftNearstCandleIndex;
        numberOfPlates++;
        countOfPlates[i] = numberOfPlates;
      }
    }
    int rightNearestCandelIndex = -1;
    for (int i = s.size() - 1; i >= 0; i--) {
      if (s[i] == '|') {
        rightNearestCandelIndex = i;
        rightIndex[i] = rightNearestCandelIndex;
      } else {
        rightIndex[i] = rightNearestCandelIndex;
      }
    }
    // get ans
    vector<int> ans(queries.size(), 0);
    for (int i = 0; i < queries.size(); i++) {
      int startIndex = queries[i][0];
      int endIndex = queries[i][1];
      int leftPlateIndex = rightIndex[startIndex];
      int rightPlateIndex = leftIndex[endIndex];
      if (leftPlateIndex == -1 || rightPlateIndex == -1 ||
          rightPlateIndex < leftPlateIndex) {
        continue;
      }
      ans[i] = countOfPlates[rightPlateIndex] - countOfPlates[leftPlateIndex];
    }
    // return
    return ans;
  }
};

int main() {
  Solution solve;
  string test = "**|**|***|";
  vector<vector<int>> queries = {{2, 5}, {5, 9}};
  vector<int> res = solve.platesBetweenCandles(test, queries);
  return 0;
}