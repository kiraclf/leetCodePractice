#include <string>
using namespace std;
class Solution {
 public:
  string fractionToDecimal(int numerator, int denominator) {
    string ans = "";
    int integerPart = numerator / denominator;
    // integer part.
    if (integerPart == 0) {
      ans.insert(0, "0");
    } else {
      while (integerPart != 0) {
        ans.insert(0, string(1,'0' + (integerPart % 10)));
        integerPart = integerPart / 10;
      }
    }
    return ans;
  }
};