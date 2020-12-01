#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int size = cost.size();
        if ( size <= 2) return 0;
        int oneStepAway = 0;
        int twoStepAway = 0;
        for (int i = 2; i <= size; i++) {
            int currentCost = min((oneStepAway + cost[i -1]), (twoStepAway + cost[i - 2]));
            twoStepAway = oneStepAway;
            oneStepAway = currentCost;
        }
        return oneStepAway;        
    }
};