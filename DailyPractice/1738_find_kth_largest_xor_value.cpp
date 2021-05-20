#include <vector>
#include <queue>
using namespace std;
class Solution {
 public:
  int kthLargestValue(vector<vector<int>>& matrix, int k) {
    // Cache vector
    priority_queue<int, vector<int>, greater<int>> cache;
    // Generate matrix
    addValueToQueue(matrix[0][0], cache, k);
    for (int i = 1; i < matrix[0].size(); i++) {
      matrix[0][i] = matrix[0][i-1] ^ matrix[0][i];
      addValueToQueue(matrix[0][i], cache, k);
    }
    for (int i = 1; i < matrix.size(); i++) {
      matrix[i][0] = matrix[i-1][0] ^ matrix[i][0];
      addValueToQueue(matrix[i][0], cache, k);
    }
    for (int i = 1; i < matrix.size(); i++) {
      for (int j = 1; j < matrix[i].size(); j++) {
        matrix[i][j] = matrix[i][j] ^ matrix[i-1][j] ^ matrix[i][j-1] ^ matrix[i-1][j-1];
        addValueToQueue(matrix[i][j], cache, k);
      }
    }
    return cache.top();
  }

  void addValueToQueue(int value,
                       priority_queue<int, vector<int>, greater<int>> &queue, int k) {
                         if (queue.size() < k) {
                           queue.push(value);
                         } else {
                           if (value > queue.top()) {
                             queue.pop();
                             queue.push(value);
                           }
                         }
                       }
};

int main() {
  Solution solve;
  vector<int> test1 = {5,2};
  vector<int> test2 = {1,6};
  vector<vector<int>> test = {{3,10,9,5,5,7}, {9,3,0,6,1,6}, {10,2,9,10,10,7}};
  int result = solve.kthLargestValue(test, 18);
  return 0;
}