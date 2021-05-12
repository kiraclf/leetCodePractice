#include <vector>
using namespace std;

class Solution {
 public:
  int minDays(vector<int>& bloomDay, int m, int k) {
    // too few flowers
    if (m * k > bloomDay.size()) {
      return -1;
    }
    // find max days
    int maxDay = 0;
    for (auto waitDay : bloomDay) {
      maxDay = max(waitDay, maxDay);
    }
    // binary search
    int left = 0;
    int right = maxDay;
    while (left < right) {
      int mid = left + (right - left) / 2;
      if (canBindFlower(mid, bloomDay, m, k)) {
        right = mid;
      } else {
        left = mid + 1;
      }
    }
    if (left <= maxDay) {
      return left;
    } else {
      return -1;
    }
  }

  bool canBindFlower(int currentDay, vector<int>& bloomDay, int m, int k) {
    int start = -1;
    int end = 0;
    int totalCount = 0;
    while (end < bloomDay.size()) {
      if (bloomDay[end] > currentDay) {
        // waiting
        if (start != -1 && end - start>= k) {
          totalCount += (end - start) / k;
          if (totalCount >= m) {
            return true;
          }
        }
        start = -1;
        end++;
      } else {
        // bloom
        if (start == -1) {
          start = end;
        }
        end++;
      }
    }
    end--;
    if (start != -1 && bloomDay[end] <= currentDay) {
      totalCount += (end - start + 1) / k;
    }
    return totalCount >= m;
  }
};

int main() {
  vector<int> bloom = {1, 10, 2, 9, 3, 8, 4, 7, 5, 6};
  Solution solve;
  int days = solve.minDays(bloom, 4, 2);
  return 0;
}