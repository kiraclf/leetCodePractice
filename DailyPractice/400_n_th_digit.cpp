#include <math.h>

#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
 public:
  int findNthDigit(int n) {
    int start = 1;
    int end = INT_MAX;
    int ans = 0;
    while (start <= end) {
      int mid = start + ((end - start) >> 1);
      pair<int, long long> midRes = countOfDigitSum(mid);
      long long smallest = midRes.second - (long long)(midRes.first - 1);
      long long largest = midRes.second;
      if ((long long)n >= smallest && (long long)n <= largest) {
        int value = mid;
        int digitIndex = largest - n;
        while (digitIndex >= 0) {
          ans = value % 10;
          value /= 10;
          digitIndex--;
        }
        break;
      } else if ((long long)n > largest) {
        start = mid + 1;
      } else {
        end = mid - 1;
      }
    }
    return ans;
  }

  /// 计算当前数字的最大 digit 序号
  ///
  /// pair<int, int> 0: 位数, 1: 序号
  pair<int, long long> countOfDigitSum(int n) {
    int number = n;
    int length = 0;
    while (n != 0) {
      length++;
      n /= 10;
    }
    // 计算小一位的数字之和
    long long digitSize = 9;
    long long totalDigitCount = 0;
    for (int i = 1; i < length; i++) {
      totalDigitCount += digitSize * i;
      digitSize *= 10;
    }
    // 计算同位的数字之和
    long long sameDigitCount = number - pow(10, length - 1) + 1;
    totalDigitCount += sameDigitCount * length;
    return pair<int, long long>(length, totalDigitCount);
  }
};

int main() {
  Solution solve;
  int res = solve.findNthDigit(3);
  return 0;
}