#include <string>
using namespace std;
class Solution {
 public:
  bool checkRecord(string s) {
    int absentCount = 0;
    int sequenceLateCount = 0;
    bool lateLargerThanThree = false;
    for (int i = 0; i < s.size(); i++) {
      char current = s[i];
      if (current == 'A') {
        absentCount++;
        sequenceLateCount = 0;
      } else if (current == 'L') {
        sequenceLateCount++;
        if (sequenceLateCount >= 3) {
          lateLargerThanThree = true;
        }
      } else {
        sequenceLateCount = 0;
      }
    }
    return (absentCount < 2) && !lateLargerThanThree;
  }
};

int main() {
  Solution solve;
  bool result1 = solve.checkRecord("PPALLP");
  bool result2 = solve.checkRecord("PPALLL");
  return 0;
}