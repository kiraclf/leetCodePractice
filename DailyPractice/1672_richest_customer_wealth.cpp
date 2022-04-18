#include <vector>
using namespace std;
class Solution {
 public:
  int maximumWealth(vector<vector<int>>& accounts) {
    int maxRes = 0;
    for (int i = 0; i < accounts.size(); i++) {
      int customerSum = 0;
      for (int j = 0; j < accounts[i].size(); j++) {
        customerSum += accounts[i][j];
      }
      maxRes = max(customerSum, maxRes);
    }
    return maxRes;
  }
};