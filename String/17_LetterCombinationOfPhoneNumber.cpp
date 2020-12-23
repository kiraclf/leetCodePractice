#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        int length = digits.size();
        vector<string> ans;
        if (length < 1) {
             return ans;
         }
        string temp = "";
        dfs(0, temp, ans, digits);
        return ans;
    }

    void dfs(int currentIndex, string &temp, vector<string> &ans, string digits) {
        if (currentIndex == digits.size()) {
            ans.push_back(temp);
            return;
        }
        char currentCharacter = digits[currentIndex];
        int count = currentCharacter == '7' || currentCharacter == '9' ? 4 : 3;
        for (int i = 0; i < count; i++) {
            int spacing = currentCharacter - '2';
            if (currentCharacter >= '8') {
                temp.push_back(digits[currentIndex] + 47 + i + 2 * spacing + 1);
            } else {
                temp.push_back(digits[currentIndex] + 47 + i + 2 * spacing);
            }
            dfs(currentIndex + 1, temp, ans, digits);
            temp.pop_back();
        }
    }
};

int main() {
    Solution solve;
    vector<string> ans = solve.letterCombinations("23");
    return 0;
}