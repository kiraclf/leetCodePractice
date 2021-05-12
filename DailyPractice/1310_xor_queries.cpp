#include <vector>
using namespace std;
class Solution {
 public:
  vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
    // change arr to xor sum
    for (int i = 1; i < arr.size(); i++) {
      arr[i] = arr[i] ^ arr[i-1];
    }
    // result 
    vector<int> result(queries.size(), 0);
    // process
    for (int i = 0; i < queries.size(); i++) {
      int leftIndex = queries[i][0];
      int rightIndex = queries[i][1];
      if (leftIndex == 0) {
        result[i] = arr[rightIndex];
      } else {
        result[i] = arr[rightIndex] ^ arr[leftIndex-1];
      }
    }
    return result;
  }
};

int main() {
  Solution solve;
  vector<int> arr = {1,3,4,8};
  vector<vector<int>> queries = {{0,1}, {1,2}, {0,3}, {3,3}};
  vector<int> result = solve.xorQueries(arr, queries);
  return 0;
}