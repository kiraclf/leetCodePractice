#include <cmath>
using namespace std;
class Solution {
 public:
  int divide(int dividend, int divisor) {
    bool posistive = false;
    if ((dividend >= 0 && divisor >= 0) || (divisor < 0 && dividend < 0)) {
      posistive = true;
    }
    dividend = abs(dividend);
    divisor = abs(divisor);
    int result = 0;
    int current = 0;
    while (current <= dividend) {
      current += divisor;
      if (posistive && result == INT32_MAX) {
        // 整数溢出
        return INT32_MAX;
      } else if (!posistive && result == (INT32_MAX - 1)) {
        // 负数溢出
        return INT32_MAX;
      }
      if (current > dividend) {
        if (posistive) {
          return result;
        } else {
          int fixNum = INT32_MAX - result + 1;
          return (fixNum | (1 << 31));
        }
      } else if (current == dividend) {
        result += 1;
        if (posistive) {
          return result;
        } else {
          int fixNum = INT32_MAX - result + 1;
          return (fixNum | (1 << 31));
        }
      }
      result += 1;
    }
    if (posistive || result == 0) {
      return result;
    } else {
      int fixNum = INT32_MAX - result + 1;
      return (fixNum | (1 << 31));
    }
  }
};

int main() {
  Solution solve;
  int res = solve.divide(-2147483648, -1);
  return 0;
}