#include <vector>
#include <queue>
using namespace std;
struct Army {
    int row;
    int count;

    friend bool operator<(const Army &a, const Army &b){
        if (a.count < b.count) {
            return true;
        } else if (a.count > b.count) {
            return false;
        } else {
            return a.row < b.row;
        }
    }
};
struct cmp2
{
    bool operator()(Army a, Army b) {
        return a < b;
    }
};

class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        priority_queue<Army, vector<Army>, cmp2> queue;
        for (int i = 0; i < mat.size(); i++) {
            Army rowArmy;
            rowArmy.row = i;
            int strength = 0;
            for (int j = 0; j < mat[i].size(); j++) {
                if (mat[i][j] == 1) {
                    strength++;
                } else {
                    break;
                }
            }
            rowArmy.count = strength;
            if (queue.size() < k) {
                queue.push(rowArmy);
            } else {
                Army top = queue.top();
                if (rowArmy < top) {
                    queue.pop();
                    queue.push(rowArmy);
                }
            }
        }
        vector<int> result;
        while (!queue.empty()) {
            Army top = queue.top();
            queue.pop();
            result.push_back(top.row);
        }
        reverse(result.begin(), result.end());
        return result;
    }
};

int main() {
    Solution solve;
    vector<vector<int>> test = {{1,1,0,0,0}, {1,1,1,1,0}, {1,0,0,0,0}, {1,1,0,0,0},{1,1,1,1,1}};
    vector<int> res = solve.kWeakestRows(test, 3);
    return 0;
}