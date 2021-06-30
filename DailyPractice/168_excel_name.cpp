#include <string>
using namespace std;
class Solution {
 public:
  string convertToTitle(int columnNumber) {
    string ans;
    while (columnNumber > 0) {
      int a0 = (columnNumber - 1) % 26 + 1;
      ans += a0 - 1 + 'A';
      columnNumber = (columnNumber - a0) / 26;
    }
    reverse(ans.begin(), ans.end());
    return ans;
  }
};

       int
       main() {
  Solution solve;
  string result = solve.convertToTitle(701);
  return 0;
}