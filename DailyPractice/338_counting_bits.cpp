/*
--- 题目描述 ---
给定一个非负整数 num。对于 0 ≤ i ≤ num 范围中的每个数字 i ，计算其二进制数中的 1
的数目并将它们作为数组返回。
--- 官方题解 ---
* 对于奇数,它一定比前面的那个偶数多一个1,因此多的就是最低位的1
* 对于偶数,偶数中1的个数,一定与除以2之后的那个数一样多
* 由此 dp(i) = i % 2 == 0 ? dp(i/2) : dp(i-1) + 1
* dp(0) = 0
*/
#include <vector>
using namespace std;
class Solution {
 public:
  vector<int> countBits(int num) {
    vector<int> result(num + 1);
    result[0] = 0;
    for (int i = 1; i <= num; i++) {
      if (i % 2 == 1) {
        result[i] = result[i -1] + 1;
      } else {
        result[i] = result[i>>1];
      }
    }
    return result;
  }

  vector<int> brutalCountBits(int num) {
    vector<int> res;
    for (int number = 0; number <= num; number++) {
      int count = countIntegerBits(number);
      res.push_back(count);
    }
    return res;
  }

  // brute force
  int countIntegerBits(int num) {
    int count = 0;
    while (num != 0) {
      if ((num & 0x1) == 1) {
        count++;
      }
      num = num >> 1;
    }
    return count;
  }
};

int main() {
  Solution solve;
  vector<int> result = solve.brutalCountBits(5);
  return 0;
}