#include <unordered_map>
#include <vector>
using namespace std;
bool myLess(vector<int>& a, vector<int>& b) { return a[0] < b[0]; }
class Solution {
 public:
  vector<int> findRightInterval(vector<vector<int>>& intervals) {
    // key: left, value: (right, index)
    unordered_map<int, pair<int, int>> cache;
    for (int i = 0; i < intervals.size(); i++) {
      cache[intervals[i][0]] = pair<int, int>(intervals[i][1], i);
    }
    sort(intervals.begin(), intervals.end(), myLess);
    vector<int> ans(intervals.size(), -1);
    // search
    for (int i = 0; i < intervals.size(); i++) {
      int rightValue = intervals[i][1];
      int left = i + 1;
      int right = intervals.size() - 1;
      while (left <= right) {
        int mid = left + (right - left) / 2;
        if (intervals[mid][0] < rightValue) {
          left = mid + 1;
        } else {
          right = mid - 1;
        }
      }
      int ansIndex = left == intervals.size() ? -1 : left;
      if (ansIndex == -1) {
        // not found
        ans[cache[intervals[i][0]].second] = -1;
      } else {
        ans[cache[intervals[i][0]].second] =
            cache[intervals[ansIndex][0]].second;
      }
    }
    return ans;
  }
};

int main() {
  Solution solve;
  vector<vector<int>> test = {{1, 2}};
  auto ans = solve.findRightInterval(test);
  return 0;
}