#include <vector>
using namespace std;
/**
* Find all valid combinations of k numbers that sum up to n such that the following conditions are true:
* Only numbers 1 through 9 are used.
* Each number is used at most once.
* Return a list of all possible valid combinations. 
* The list must not contain the same combination twice, and the combinations may be returned in any order.
**/
class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> current;
        dfs(0, k, current, n, ans);
        return ans;
    }

    void dfs(int sum, int targetDepth, vector<int> &current, int target, vector<vector<int>> &ans) {
        // terminator
        int currentDepth = current.size();
        if ( currentDepth >= targetDepth) {
            if (currentDepth == targetDepth && sum == target) {
                ans.push_back(current);
            }
            return;
        }
        if ( sum >= target ) {
            return;
        }
        // dig down
        int lastValue = current.size() == 0 ? 0 : current.back();
        for (int i = lastValue + 1; i < 10; i++) {
            sum += i;
            current.push_back(i);
            dfs(sum, targetDepth, current, target, ans);
            current.pop_back();
            sum -= i;
        }
    }
};

int main() {
    Solution test;
    vector<vector<int>> ans = test.combinationSum3(9, 45);
    return 0;
}