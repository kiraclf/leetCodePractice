#include <vector>
using namespace std;
class Solution {
 public:
  int chalkReplacer(vector<int>& chalk, int k) {
    int roundSum = 0;
    for (auto need : chalk) {
      roundSum += need;
    }
    int emptyRound = k % roundSum;
    int emptyIndex = 0;
    while (emptyIndex < chalk.size()) {
      if (emptyRound - chalk[emptyIndex] < 0) {
        return emptyIndex;
      }
      emptyRound -= chalk[emptyIndex];
      emptyIndex++;
    }
    // will not entery here.
    return -1;
  }
};

int main() {
  Solution solve;
  vector<int> test = {3,4,1,2};
  int chalk = 25;
  int idnex = solve.chalkReplacer(test, chalk);
  return 0;
}