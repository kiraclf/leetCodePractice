#include <util.h>
using namespace std;
class Solution {
 public:
  int hammingWeight(u_int32_t n) {
    int count = 0;
    u_int32_t mask = 1;
    while ( n != 0) {
      if (count & mask == 1) {
        count++;
      }
      n = n >> 1;
    }
    return count;
  }
};