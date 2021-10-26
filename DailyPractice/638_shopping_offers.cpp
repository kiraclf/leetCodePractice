#include <vector>
using namespace std;
class Solution {
 private:
 public:
  int shoppingOffers(vector<int>& price, vector<vector<int>>& special,
                     vector<int>& needs) {
    // calculate min cost
    int minCost = 0;
    for (int i = 0; i < needs.size(); i++) {
      minCost += (price[i] * needs[i]);
    }
    vector<int> currentBuying(needs.size(), 0);
    dfs(price, special, needs, minCost, 0, currentBuying);
    return minCost;
  }

  void dfs(vector<int>& price, vector<vector<int>>& special, vector<int>& needs,
           int& minCost, int currentCost, vector<int>& currentBuying) {
    if (currentCost > minCost) {
      return;
    }
    bool needRequired = true;
    for (int i = 0; i < currentBuying.size(); i++) {
      if (currentBuying[i] > needs[i]) {
        return;
      } else if (currentBuying[i] < needs[i]) {
        needRequired = false;
        break;
      }
    }
    if (needRequired) {
      minCost = currentCost;
      return;
    }
    // choose package
    for (int i = 0; i < special.size(); i++) {
      for (int j = 0; j < special[i].size(); j++) {
        currentBuying[j] += special[i][j];
      }
      dfs(price, special, needs, minCost,
          currentCost + special[i][special[i].size() - 1], currentBuying);
      for (int j = 0; j < special[i].size(); j++) {
        currentBuying[j] -= special[i][j];
      }
    }
    // choose single
    for (int i = 0; i < price.size(); i++) {
      currentBuying[i] += 1;
      dfs(price, special, needs, minCost, currentCost + price[i],
          currentBuying);
      currentBuying[i] -= 1;
    }
  }
};

int main() {
  vector<int> price = {2, 5};
  vector<vector<int>> special = {{3, 0, 5}, {1, 2, 10}};
  vector<int> needs = {3, 2};
  Solution solve;
  int mindCost = solve.shoppingOffers(price, special, needs);
  return 0;
}