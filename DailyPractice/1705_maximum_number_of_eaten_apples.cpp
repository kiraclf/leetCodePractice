#include <vector>
using namespace std;

bool compare(pair<int, pair<int, int>> pairA, pair<int, pair<int, int>> pairB) {
  if (pairA.first != pairB.first) {
    return pairA.first < pairB.first;
  } else {
    return pairA.second.first < pairB.second.first;
  }
}
class Solution {
 public:
  int eatenApples(vector<int>& apples, vector<int>& days) {
    // greedy
    // pair<int, int> first: the last day can eat, second: the first grow day,
    // third: count
    vector<pair<int, pair<int, int>>> appleTree;
    for (int i = 0; i < apples.size(); i++) {
      if (apples[i] == 0) {
        continue;
      }
      appleTree.push_back(pair<int, pair<int, int>>(
          i + days[i] - 1, pair<int, int>(i, apples[i])));
    }
    sort(appleTree.begin(), appleTree.end(), compare);
    int currentDay = 0;
    int maxNumber = 0;
    while (appleTree.size() != 0) {
      if (appleTree[0].first < currentDay) {
        appleTree.erase(appleTree.begin());
        continue;
      }
      // 吃最早的一个苹果, 如果剩余0,则销毁该记录
      if (currentDay >= appleTree[0].second.first) {
        appleTree[0].second.second -= 1;
        maxNumber += 1;
        if (appleTree[0].second.second == 0) {
          appleTree.erase(appleTree.begin());
        }
      }
      currentDay++;
    }
    return maxNumber;
  }
};

int main() {
  Solution solve;
  vector<int> apples = {1, 2, 3, 5, 2};
  vector<int> days = {3, 2, 1, 4, 2};
  int max = solve.eatenApples(apples, days);
  return 0;
}