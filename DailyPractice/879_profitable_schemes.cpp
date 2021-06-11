#include <vector>
using namespace std;
class Solution {
 public:
  int profitableSchemes(
    int n, 
    int minProfit, 
    vector<int>& group,
    vector<int>& profit) {
      // Create dp array.
      int groupCount = group.size();
      vector<int> peopleVec(n + 1, 0);
      vector<vector<int>> profitVec(minProfit + 1, peopleVec);
      vector<vector<vector<int>>> groupVc(groupCount + 1, profitVec);
      groupVc[0][0][0] = 1;
      // Dp caculate.
      for (int i = 1; i < groupVc.size(); i++) { // leading group
        for (int j = 0; j < groupVc[0].size(); j++) { // mini profit
          for (int k = 1; k < groupVc[0][0].size(); k++) { // people limit
                    // Can't choose i-1 work
                    if (k < group[i-1]) {
                      groupVc[i][j][k] = groupVc[i-1][j][k];
                    } else {
                      // Can choose i-1 work
                      groupVc[i][j][k] =
                          groupVc[i - 1][j][k] + // Don't choose i - 1
                          groupVc[i - 1][max(0, j - profit[i - 1])] // Choose i - 1
                                 [k - group[i - 1]] % 1000000007;
                    }
          }
        }
      }
      // Result
      int reuslt = 0;
      for (int i = 0; i <= groupVc[0][0].size(); i++) {
        reuslt = (reuslt + groupVc[groupCount][minProfit][i]) % 1000000007;
      }
      return reuslt;
    }
};

int main() {
  Solution solve;
  vector<int> group = {2,2};
  vector<int> profit = {2,3};
  int result = solve.profitableSchemes(5,3,group, profit);
  return 0;
}