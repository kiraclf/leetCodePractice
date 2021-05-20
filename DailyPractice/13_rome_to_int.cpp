#include <string>
#include <unordered_map>
using namespace std;
class Solution {
 public:
  int romanToInt(string s) {
    // Digit map.
    unordered_map<string, int> romanMap = {
      {"I", 1},
      {"IV", 4},
      {"V", 5},
      {"IX", 9},
      {"X", 10},
      {"XL", 40},
      {"L", 50},
      {"XC", 90},
      {"C", 100},
      {"CD", 400},
      {"D", 500},
      {"CM", 900},
      {"M", 1000}
    };
    // Process start.
    int result = 0;
    int start = 0;
    while (start < s.size()) {
      // Check length two
      if (start + 1 < s.size()) {
        string twoDigit = s.substr(start, 2);
        if (romanMap.find(twoDigit) != romanMap.end()) {
          result += romanMap[twoDigit];
          start += 2;
        } else {
          result += romanMap[s.substr(start, 1)];
          start += 1;
        }
      } else {
        // length one
        result += romanMap[s.substr(start, 1)];
        start += 1;
      }
    }
    return result;
  }
};

int main() {
  Solution solve;
  int result = solve.romanToInt("MCMXCIV");
  return 0;
}