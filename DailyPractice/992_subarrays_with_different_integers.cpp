#include <vector>
#include <unordered_set>
#include <unordered_map>
using namespace std;
/*
给定一个正整数数组 A，如果 A 的某个子数组中不同整数的个数恰好为 K，则称 A
的这个连续、不一定独立的子数组为好子数组。

（例如，[1,2,3,1,2] 中有 3 个不同的整数：1，2，以及 3。）

返回 A 中好子数组的数目。
*/

class Solution {
 public:
  // 该方法超时
  int subarraysTryWithKDistinct(vector<int>& A, int K) {
    int res = 0;
    unordered_set<int> cache;
    for (int i = 0; i < A.size(); i++) {
      int left = i, right = i;
      cache.clear();
      while (right < A.size()) {
        int rightValue = A[right];
        if ( cache.find(rightValue) == cache.end()) {
          // distinct
          cache.insert(rightValue);
        }
        if ( cache.size() == K) {
          res++;
        }
        if ( cache.size() > K) {
          break;
        }
        right++;
      }
    }
    return res;
  }

  int subarraysWithKDistinct(vector<int>& A, int K){
    return atMost(A, K) - atMost(A, K - 1);
  }

  int atMost(vector<int>& A, int K) {
    int N = A.size();
    int res = 0;
    unordered_map<int, int> window;
    for (int i = 0, j = 0; j < N; j++) {
      window[A[j]] ++;
      while (window.size() > K) {
        window[A[i]]--;
        if (window[A[i]] == 0) {
          window.erase(A[i]);
        }
        i++;
      }
      res += (j - i + 1);
    }
    return res;
  }
};

int main() {
    vector<int> toTest = {1, 2, 1, 2, 3};
    Solution solve;
    int result = solve.subarraysWithKDistinct(toTest, 2);
    return 0;
}