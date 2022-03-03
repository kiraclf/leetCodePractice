#include <string>
using namespace std;
/*
 * --- 思路 ---
 * dfs 直接进行遍历 (超时)
 * --- DP ---
 * dp[i] 为 str[0...i]的译码总数
 * * s[i] == '0' 如果 s[i-1] == 1 或者 s[i-1] == 2, 那么 dp[i] = dp[i-2]
 * * s[i-1] == '1' 那么 dp[i] = dp[i-1] + dp[i-2]
 * * s[i-1] == '2' 并且 1 <= s[i] <= 6 dp[i] = dp[i-1] + dp[i-2]
 */
class Solution {
public:
    int numBrutalDecodings(string s) {
        int count = 0;
        dfs(s, 0, count);
        return count;
    }

    int numDecodings(string s) {
    if (s[0] == '0') return 0;
    int pre = 1, curr = 1;//dp[-1] = dp[0] = 1
    for (int i = 1; i < s.size(); i++) {
        int tmp = curr;
        if (s[i] == '0')
            if (s[i - 1] == '1' || s[i - 1] == '2') curr = pre;
            else return 0;
        else if (s[i - 1] == '1' || (s[i - 1] == '2' && s[i] >= '1' && s[i] <= '6'))
            curr = curr + pre;
        pre = tmp;
    }
    return curr;
    }

    void dfs(string s, int currentIndex, int& count) {
        // terminate
        if (currentIndex >= s.size()) {
            count++;
            return;
        }
        char current = s[currentIndex];
        if (current != '0') {
            // single character
            dfs(s, currentIndex + 1, count);
        }
        // combine two character
        if (currentIndex + 1 < s.size() && current != '0') {
            if (current > '2' || (current == '2' && s[currentIndex + 1] > '6')) {
                return;
            } else {
                dfs(s, currentIndex + 2, count);
            }
        }
    } 


};

int main() {
    Solution solve;
    int vlaue = solve.numDecodings("2611055971756562");
    return 0;
}