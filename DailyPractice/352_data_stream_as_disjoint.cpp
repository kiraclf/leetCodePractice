#include <vector>
using namespace std;
class SummaryRanges {
 private:
  vector<int> cache;
  vector<vector<int>> intervals;
 public:
  SummaryRanges() {
    cache = vector<int>(10001, 0);
    intervals = vector<vector<int>>();
  }

  void addNum(int val) {
    if (cache[val] == 0) {
      // new added
      cache[val] += 1;
      bool added = false;
      for (int i = 0; i < intervals.size(); i++) {
        if (intervals[i][1] + 1 == val || intervals[i][0] - 1 == val) {
          if (intervals[i][1] + 1 == val) {
            intervals[i][1] += 1;
            added = true;
            break;
          } else {
            intervals[i][0] -= 1;
            added = true;
            break;
          }
        }
      }
      if (!added) {
        intervals.push_back({val, val});
        reformInterval();
      } else {
        reformInterval();
      }

    }
    // added, don't need process
  }

  void reformInterval() {
    if (intervals.size() <= 1) {
      return;
    }
      sort(intervals.begin(), intervals.end());
    int beforeEnd = -2;
    for (int i = 0; i < intervals.size(); i++) {
      int start = intervals[i][0];
      int end = intervals[i][1];
      if (start <= beforeEnd + 1) {
        intervals[i - 1][1] = intervals[i][1];
        intervals.erase(std::begin(intervals) + i);
        i--;
      } else {
        beforeEnd = intervals[i][1];
      }
    }
  }

  vector<vector<int>> getIntervals() {
    return intervals;
  }
};
typedef vector<vector<int>> Res;
int main() {
  SummaryRanges * obj = new SummaryRanges();
  obj->addNum(6);
  Res res0 = obj->getIntervals();
  obj->addNum(6);
  obj->addNum(0);
  obj->addNum(4);
  obj->addNum(8);
  obj->addNum(7);
  obj->addNum(6);
  obj->addNum(4);
  obj->addNum(7);
  obj->addNum(5);
  Res res1 = obj->getIntervals();
  return 0;
}