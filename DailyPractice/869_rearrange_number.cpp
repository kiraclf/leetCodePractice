#include <string>
#include <unordered_set>
#include <vector>
using namespace std;
class Solution {
 public:
  bool reorderedPowerOf2(int n) {
    // get n max and n min
    vector<int> n_digit;
    while (n != 0) {
      n_digit.push_back(n % 10);
      n = n / 10;
    }
    sort(n_digit.begin(), n_digit.end());
    reverse(n_digit.begin(), n_digit.end());
    int maxValue = 0;
    for (int i = 0; i < n_digit.size(); i++) {
      maxValue = maxValue * 10 + n_digit[i];
    }
    reverse(n_digit.begin(), n_digit.end());
    if (n_digit[0] == 0) {
      for (int i = 1; i < n_digit.size(); i++) {
        if (n_digit[i] != 0) {
          n_digit[0] = n_digit[i];
          n_digit[i] = 0;
          break;
        }
      }
    }
    int minValue = 0;
    for (int i = 0; i < n_digit.size(); i++) {
      minValue = minValue * 10 + n_digit[i];
    }
    // create two_cache.
    vector<int> two_cache;
    long long current = 1;
    while (current <= maxValue) {
      two_cache.push_back(current);
      current *= 2;
    }
    // filter possible 2's
    unordered_set<string> possibleString;
    for (int i = 0; i < two_cache.size(); i++) {
      if (two_cache[i] >= minValue && two_cache[i] <= maxValue) {
        possibleString.insert(getDigitString(two_cache[i]));
      }
      if (two_cache[i] > maxValue) {
        break;
      }
    }
    return possibleString.find(getDigitString(minValue)) !=
           possibleString.end();
  }

  string getDigitString(int number) {
    vector<int> digitCount(10, 0);
    while (number != 0) {
      int digit = number % 10;
      number = number / 10;
      digitCount[digit]++;
    }
    string current = "";
    for (auto digit : digitCount) {
      current.push_back('0' + digit);
    }
    return current;
  }
};

int main() {
  Solution solve;
  bool res = solve.reorderedPowerOf2(1);
  return 0;
}