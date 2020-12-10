#include <vector>
using namespace std;

class Solution {
public:
    int sumSubseqWidths(vector<int>& A) {
        // generate all subArrays
        vector<vector<int>> subArrays = getAllSubArrays(A);
        // cacualte width
        int sum = 0;
        for (auto sub : subArrays) {
            if (sub.size() == 1) {
                continue;
            } else {
                int width = sub[sub.size() - 1] - sub[0];
                sum = (sum + width) % (1000000007);
            }
        }
        return sum;
    }

    vector<vector<int>> getAllSubArrays(vector<int>& array) {
        vector<vector<int>> ans;
        vector<int> temp;
        sort(array.begin(), array.end());
        dfsGenearte(0, temp, array, ans);
        return ans;
    }

    void dfsGenearte(int currentIndex,vector<int> & currentArray,vector<int> & array, vector<vector<int>> &ans) {
        if (currentArray.size() != 0) {
            ans.push_back(currentArray);
        }
        if (currentIndex >= array.size()) {
            return;
        }
        for (int i = currentIndex; i < array.size(); i++) {
            currentArray.push_back(array[i]);
            dfsGenearte(i+1, currentArray, array, ans);
            currentArray.pop_back();
        }
    }
};

int main() {
    Solution solve;
    vector<int> input = {6,13,2,15,1,25,12,30,14,26,13,18,37,6,5,9,31,33,22,29};
    int ans = solve.sumSubseqWidths(input);
    return 0;
}