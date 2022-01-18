#include <string>
#include <vector>
using namespace std;
class Solution {
 public:
  int findMinDifference(vector<string>& timePoints) {
    vector<int> timeList(timePoints.size() * 2, 0);
    for (int i = 0; i < timeList.size(); i++) {
      int mintue = getMinutes(timePoints[i % timePoints.size()]);
      if (i >= timePoints.size()) {
        timeList[i] = mintue + 24 * 60;
      } else {
        timeList[i] = mintue;
      }
    }
    sort(timeList.begin(), timeList.end());
    int ans = INT_MAX;
    for (int i = 1; i < timeList.size(); i++) {
      ans = min(ans, timeList[i] - timeList[i - 1]);
    }
    return ans;
  }

 private:
  int getMinutes(string time) {
    string hourS = time.substr(0, 2);
    string minuteS = time.substr(3, 2);
    int hour = atoi(hourS.c_str());
    int minute = atoi(minuteS.c_str());
    return hour * 60 + minute;
  }
};

int main() {
  Solution solve;
  vector<string> times = {"00:00", "23:59"};
  int diff = solve.findMinDifference(times);
  return 0;
}