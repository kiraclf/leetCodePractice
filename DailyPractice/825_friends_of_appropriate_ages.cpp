#include <vector>
using namespace std;
class Solution {
 public:
  int numFriendRequests(vector<int>& ages) {
    vector<int> ageMap(121, 0);
    for (auto age : ages) {
      ageMap[age] += 1;
    }
    int res = 0;
    for (int i = 0; i < ageMap.size(); i++) {
      if (i <= 14 || ageMap[i] == 0) {
        continue;
      }
      int topValue = i;
      int minValue = i / 2 + 8;
      for (int j = minValue; j <= topValue; j++) {
        int currentCount = ageMap[i] * ageMap[j];
        if (i == j) {
          currentCount -= ageMap[i];
        }
        res += currentCount;
      }
    }
    return res;
  }
};

int main() {
  Solution solve;
  vector<int> test = {16, 16};
  int count = solve.numFriendRequests(test);
  return 0;
}