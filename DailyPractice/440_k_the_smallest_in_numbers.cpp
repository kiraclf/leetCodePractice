#include <algorithm>
using namespace std;
class Solution {
 private:
  // 获取以 cur 为 root 的节点的总个数
  int getSteps(int cur, long n) {
    int steps = 0;
    long first = cur;
    long last = cur;
    while (first <= n) {
      steps += (min(last, n) - first + 1);
      first = first * 10;
      last = last * 10 + 9;
    }
    return steps;
  }

 public:
  int findKthNumber(int n, int k) {
    int curr = 1;
    k--;
    while (k > 0) {
      // 获取以 curr 开头的 node 的数量
      int steps = getSteps(curr, n);
      if (steps <= k) {
        // 当前的开头不够
        k -= steps;
        curr++;
      } else {
        curr = curr * 10;
        k--;
      }
    }
    return curr;
  }
};

int main() {
  Solution solve;

  return 0;
}