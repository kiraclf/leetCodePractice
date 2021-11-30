#include <vector>
using namespace std;
class Solution {
 public:
  int findPoisonedDuration(vector<int>& timeSeries, int duration) {
    int totalDuration = 0;
    if (timeSeries.size() == 0) {
      return 0;
    }
    if (timeSeries.size() == 1) {
      return duration;
    }
    for (int i = 1; i < timeSeries.size(); i++) {
      if (timeSeries[i] - timeSeries[i - 1] >= duration) {
        // not affect
        totalDuration += duration;
      } else {
        totalDuration += timeSeries[i] - timeSeries[i - 1];
      }
    }
    totalDuration += duration;
    return totalDuration;
  }
};

int main() {
  Solution solve;
  vector<int> test = {1, 4};
  int res = solve.findPoisonedDuration(test, 2);
  return 0;
}