#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
 private:
  unordered_map<long long, int> cache;

 public:
  int integerReplacement(int n) {
    cache = unordered_map<long long, int>();
    return smallestChangeCount(n);
  }

  long long smallestChangeCount(long long value) {
    if (cache.find(value) != cache.end()) {
      return cache[value];
    }
    if (value < 1) {
      return INT_MAX;
    }
    if (value == 1) {
      return 0;
    }
    if (value % 2 == 0) {
      long long res = smallestChangeCount(value >> 1);
      cache[(value >> 1)] = res;
      return res + 1;
    } else {
      long long minusRes = smallestChangeCount(value - 1);
      cache[value - 1] = minusRes;
      long long biggerRes = smallestChangeCount(value + 1);
      cache[value + 1] = biggerRes;
      long long res = min(minusRes, biggerRes) + 1;
      cache[value] = res;
      return res;
    }
  }
};

int main() {
  Solution solve;
  int res = solve.integerReplacement(2147483647);
  return 0;
}