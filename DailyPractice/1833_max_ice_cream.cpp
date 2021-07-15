#include <vector>
using namespace std;
class Solution {
 public:
  int maxIceCream(vector<int>& costs, int coins) {
    sort(costs.begin(), costs.end());
    int count = 0;
    int sum = 0;
    for (int i = 0; i < costs.size(); i++) {
      sum += costs[i];
      if ( sum > coins) {
        break;
      } else {
        count++;
      }
    }
    return count;
  }
};