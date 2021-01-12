#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string temp = "";
        dfs(n, n, 0, temp, ans);
        return ans;
    }

    void dfs(int leftCount, int rightCount, int currentLeftCount, string &current, vector<string> &ans) {
        if (leftCount == 0 && rightCount == 0) {
            ans.push_back(current);
            return;
        }
        if (leftCount < 0 || rightCount < 0) {
            return;
        }
        // add left
        if (leftCount > 0) {
            current.push_back('(');
            dfs(leftCount-1, rightCount, currentLeftCount+1,current, ans);
            current.pop_back();
        }
        // add right
        if (rightCount > 0 && currentLeftCount > 0) {
            current.push_back(')');
            dfs(leftCount, rightCount-1, currentLeftCount-1, current, ans);
            current.pop_back();
        }
    }
};

int main() {
    Solution test;
    vector<string> ans = test.generateParenthesis(3);
    printf("");
    return 0;
}
