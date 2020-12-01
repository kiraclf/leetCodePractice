#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        
    }

    int maxProfitDFS(vector<int>& prices, int fee) {
        int maxProfit = 0;
        dfs(0, 0, prices, fee, maxProfit);
        return maxProfit;
    }

    void dfs(int index, int profit, vector<int>& prices, int fee, int &maxProfit) {
        if (index > prices.size()) {
            if (profit > maxProfit) {
                maxProfit = profit;
            }
            return;
        }
        // 当天可买入
        dfs(index + 1, profit - prices[index], prices, fee, maxProfit);
        // 可卖出
        dfs(index + 1, profit + prices[index] - fee, prices, fee, maxProfit);
        // 可以啥都不做
        dfs(index + 1, profit, prices, fee, maxProfit);
    }
};

int main() {
    vector<int> toSolve = {1,3,2,8,4,9};
    Solution solution;
    int result = solution.maxProfitDFS(toSolve, 2);
    return 0;
}