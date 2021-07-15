#include <vector>
#include <unordered_set>
#include <unordered_map>
using namespace std;
class Solution {
 public:
  int countPairs(vector<int>& deliciousness) {
    if (deliciousness.size() <= 1) {
      return 0;
    }
    sort(deliciousness.begin(), deliciousness.end());
    unordered_set<int> possibleSums;
    for (int possibleValue = 1; possibleValue <= (2 * deliciousness[deliciousness.size() -1]); possibleValue = possibleValue << 1) {
      possibleSums.insert(possibleValue);
    }
    int count = 0;
    unordered_map<int, int> values;
    values[deliciousness[0]] = 1;
    for (int i = 1; i < deliciousness.size(); i++) {
      int currentValue = deliciousness[i];
      for (auto possibleSum : possibleSums) {
        if (possibleSum > currentValue * 2 || possibleSum < currentValue) {
          continue;
        }
        int targetValue = possibleSum - currentValue;
        if (values.find(targetValue) != values.end()) {
          count = (count + values[targetValue]) % (1000000007);
        }
      }
      values[currentValue] += 1;
    }
    return count;
  }
};

int main() {
  Solution solve;
  vector<int> test = {1, 1, 1, 3, 3, 3, 7};
  int result = solve.countPairs(test);
  return 0;
}