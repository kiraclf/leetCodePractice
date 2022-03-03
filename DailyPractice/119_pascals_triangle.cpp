#include <vector>
using namespace std;
/*
给定一个非负索引 k，其中 k ≤ 33，返回杨辉三角的第 k 行。
*/

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> before = {1};
        vector<int> after;
        if (rowIndex == 0) {
            return {};
        }
        if ( rowIndex == 1) {
            return before;
        }
        int currentRow = 1;
        while ( currentRow <= rowIndex ) {
            for (int i = 0; i <= currentRow; i++) {
                if ( i == 0 || i == currentRow) {
                    after.push_back(1);
                } else {
                    after.push_back(before[i-1] + before[i]);
                }
            }
            before = after;
            currentRow++;
            if ( currentRow != rowIndex + 1) {
                after = vector<int>();
            }
        }
        return after;
    }
};

int main() {
    Solution solve;
    vector<int> result = solve.getRow(3);
    return 0;
}