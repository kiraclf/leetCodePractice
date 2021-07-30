#include <vector>
#include <math.h>
using namespace std;
class Solution {
 public:
  vector<int> pathInZigZagTree(int label) {
    // Find the regular number of label
    int level = 0;
    int current = 1;
    while (current < label) {
      level ++;
      current *= 2;
      if (current > label) {
        level--;
      }
    }
    if (level % 2 != 0) {
      label = pow(2, level) + pow(2, level + 1) - 1 - label;
    }
    // Generate regular result
    vector<int> res;
    res.push_back(label);
    while (label != 1) {
      res.push_back(label/2);
      label /= 2;
    }
    reverse(res.begin(), res.end());
    // Reverse needed result
    for (int i = 0; i < res.size(); i++) {
      if (i % 2 != 0) {
        res[i] = pow(2, i) + pow(2, i + 1) - 1 - res[i];
      }
    }
    return res;
  }
};

int main() {
  Solution solve;
  vector<int> list = solve.pathInZigZagTree(26);
  return 0;
}