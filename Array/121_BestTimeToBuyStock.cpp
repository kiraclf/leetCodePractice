#include <vector>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() == 0) return 0;
        int maxProfit = 0;
        int minBuy = prices[0];
        for (int i = 0; i < prices.size(); i++) {
            maxProfit = max(maxProfit, prices[i] - minBuy);
            minBuy = min(minBuy, prices[i]);
        }
        return maxProfit;
    }
};