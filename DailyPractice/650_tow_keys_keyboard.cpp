#include <vector>
using namespace std;

class Solution {
public:
    int minSteps(int n) {
        // dp[i][j] 当前记事本上有i个字符，粘贴板上有j个字符的最小操作次数
        // j <= i
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0x3f3f3f3f));
        dp[1][0] = 0;
        dp[1][1] = 1;
        for (int i = 2; i <= n; i++) {
            int minValue = INT_MAX;
            for (int j = 0; j <= i / 2; j++) {
                dp[i][j] = dp[i-j][j] + 1;
                minValue = min(minValue, dp[i][j]);
            }
            dp[i][i] = minValue + 1;
        }
        int ans = INT_MAX;
        for (int i = 0; i <=n; i++) {
            ans = min(ans, dp[n][i]);
        }
        return ans;
    }
};