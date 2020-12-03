#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& A) {
        // Exception Handler
        if (A.size() == 0 || A[0].size() == 0) return A;
        // Transform
        vector<vector<int>> ans;
        for (int x = 0; x < A[0].size(); x++) {
            vector<int> row;
            for (int y = 0; y < A.size(); y++) {
                row.push_back(A[y][x]);
            }
            ans.push_back(row);
        }
        return ans;
    }


    vector<vector<int>> officialTranspose(vector<vector<int>>& A) {
        vector<vector<int> > v(A[0].size(),vector<int>(A.size(),0));
        for(int i=0;i<A.size();i++){
            for(int j=0;j<A[i].size();j++){
                v[j][i]=A[i][j];
            }
        }
        return v;
    }
};