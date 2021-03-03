#include <vector>
#include <queue>
using namespace std;
/*
在仅包含 0 和 1 的数组 A 中，一次 K 位翻转包括选择一个长度为 K
的（连续）子数组，同时将子数组中的每个 0 更改为 1，而每个 1 更改为 0。
返回所需的 K 位翻转的最小次数，以便数组没有值为 0 的元素。如果不可能，返回 -1。
*/
/* -- 官方题解 --
  对于同一个子数组,执行两次旋转操作不会改变该子数组,所以对于每个长度为 K 的子数组,最多执行一次翻转操作.
  对于若干个K位旋转操作,改变先后顺序,并不影响最终翻转结果.
  从 A[0] 开始考虑, 如果 A[0] = 0, 那么必定要翻转从位置0开始的子数组
  如果A[0] = 1, 那么就不翻转该数组 --> 复杂度为 O(NK)

*/
class Solution {
 public:
  int minKBitFlips(vector<int>& A, int K) {
    int size = A.size();
    queue<int> que;
    int res = 0;
    for (int i = 0; i < size; i++) {
      if (!que.empty() && i >= que.front() + K) {
        que.pop();
      }
      if (que.size() % 2 == A[i]) {
        if (i + K > size) {
          return -1;
        }
        que.push(i);
        res++; 
      }
    }
    return res;
  }

  // 模拟翻转,超时
  int brutalMinKBitFlips(vector<int>& A, int K) {
    int size = A.size();
    int result = 0;
    for (int i = 0; i < size - K + 1; i++) {
      if (A[i] == 1) {
        continue;
      }
      for (int j = i; j < i + K; j++) {
        A[j] ^= 1;
      }
      result += 1;
    }
    for (int i = 0; i < size; i++) {
      if (A[i] == 0) {
        return -1;
      }
    }
    return result;
  }
};