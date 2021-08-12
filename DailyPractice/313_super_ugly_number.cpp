#include <vector>
using namespace std;
class Solution {
 public:
  int nthSuperUglyNumber(int n, vector<int>& primes) {
    // 生成只有 primes 组成的数组, 从小到大
    vector<int> primeList = {1};
    vector<int> generateList = primes;
    while (primeList.size() < n) {
      // 遍历出 generateList 中最小的值
      int smallest = INT_MAX;
      int index = -1;
      for (int i = 0; i < generateList.size(); i++) {
        if (generateList[i] < smallest) {
          smallest = generateList[i];
          index = i;
        }
      }
      if (smallest != primeList[primeList.size() - 1]) {
        primeList.push_back(smallest);
      }
      // 然后生成其下一个值, 二分查找比它大的最小值
      int smallestCurrent = smallest / primes[index];
      int bigger = 0;
      int startIndex = 0;
      int endIndex = primeList.size() - 1;
      while (startIndex <= endIndex) {
        int midIndex = startIndex + (endIndex - startIndex) / 2;
        if (primeList[midIndex] > smallestCurrent) {
          bigger = primeList[midIndex];
          endIndex = midIndex - 1;
        } else {
          startIndex = midIndex + 1;
        }
      }
      generateList[index] = bigger*primes[index];
    }
    return primeList[n-1];
  }
};

int main() {
  Solution solve;
  vector<int> primes = {2,7,13,19};
  int result = solve.nthSuperUglyNumber(12, primes);
  return 0;
}