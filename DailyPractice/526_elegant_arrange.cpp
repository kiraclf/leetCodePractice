#include <vector>
using namespace std;
class Solution {
 public:
  int countArrangement(int n) {
    vector<int> numberArr(n, 1);
    int count = 0;
    dfs(0, numberArr, n, count);
    return count;
  }

  void dfs(int currentIndex, vector<int>& numberArr, int n, int &count) {
    if (currentIndex == n) {
      count++;
      return;
    }
    int iNumber = currentIndex + 1;
    for (int i = 0; i < numberArr.size(); i++) {
      if (numberArr[i] == 0) {
        continue;
      } else {
        if ((i + 1) % iNumber == 0) {
          // 第一个条件
          numberArr[i] = 0;
          dfs(currentIndex + 1, numberArr, n, count);
          numberArr[i] = 1;
        } else if (iNumber % (i + 1) == 0) {
          // 第二个条件
          numberArr[i] = 0;
          dfs(currentIndex + 1, numberArr, n, count);
          numberArr[i] = 1;
        }
      }
    }
  }
};

int main() {
  Solution solve;
  int count = solve.countArrangement(10);
  return 0;
}