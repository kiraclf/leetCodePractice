#include <vector>
using namespace std;
class Solution {
 public:
  vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
    // 利用差分的思路
    vector<int> nums(n);
    for (auto& booking : bookings) {
      nums[booking[0] - 1] += booking[2];
      if (booking[1] < n) {
        nums[booking[1]] -= booking[2];
      }
    }
    for (int i = 1; i < n; i++) {
      nums[i] += nums[i - 1];
    }
    return nums;
  }
};

int main() {
  Solution solve;
  vector<vector<int>> books = {{1,2,10}, {2,2,15}};
  vector<int> res = solve.corpFlightBookings(books, 2);
  return 0;
}