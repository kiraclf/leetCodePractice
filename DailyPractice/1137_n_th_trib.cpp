#include <vector>
using namespace std;
class Solution {
 public:
  int tribonacci(int n) {
    vector<int> trib = {0,1,1};
    if ( n < 3) {
      return trib[n];
    }
    int current = 2;
    while (current < n) {
      int next = trib[0] + trib[1] + trib[2];
      trib[0] = trib[1];
      trib[1] = trib[2];
      trib[2] = next;
      current++;
    }
    return trib[2];
  }
};

int main() {
  Solution solve;
  int result = solve.tribonacci(4);
  return 0;
}