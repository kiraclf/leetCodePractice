/*
给定一个由若干 0 和 1 组成的数组 A，我们最多可以将 K 个值从 0 变成 1 。
返回仅包含 1 的最长（连续）子数组的长度。
*/
#include <vector>
using namespace std;
class Solution {
 public:
  int longestOnes(vector<int>& A, int K) {
    int res = 0, zeros = 0, left = 0;
    for (int right = 0; right < A.size(); right++) {
      if (A[right] == 0) zeros++;
      while (zeros > K) {
        if (A[left] == 0) {
          zeros--;
        }
        left++;
      }
      res = max(res, right - left + 1);
    }
    return res;
  }
};