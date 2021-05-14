#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
 public:
  string intToRoman(int num) {
    string result = "";
    vector<int> roamNumber = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4,1};
    vector<string> romaVect = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
    for (int i = 0; i < roamNumber.size(); i++) {
      int count = num / roamNumber[i];
      for (int j = 0; j < count; j++) {
        result += romaVect[i];
      }
      num = num - roamNumber[i] * count;
      if (num == 0) {
        return result;
      }
    }
    return result;
  }
};

int main() {
  Solution solve;
  string romaValue = solve.intToRoman(1994);
  return 0;
}