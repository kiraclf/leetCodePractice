#include <string>
#include <vector>
using namespace std;
class Solution {
 public:
  string nearestPalindromic(string n) {
    // exception
    if (n.size() == 1) {
      n[0] -= 1;
      return n;
    }
    // generate possible ans
    string ansA = n;
    string ansB = n;
    genterateTwoPairs(n, ansA, ansB);
    // cacluate diff
    string smallerAns = smaller(ansA, ansB) ? ansA : ansB;
    int aDifference = caculateDifferent(n, ansA);
    int bDifference = caculateDifferent(n, ansB);
    // return ans
    if (aDifference != bDifference) {
      return aDifference < bDifference ? ansA : ansB;
    } else {
      return smallerAns;
    }
  }

  /// Generate two possible answers.
  void genterateTwoPairs(string original, string& ansA, string& ansB) {
    int size = original.size();
    if (size % 2 != 0) {
      // middle
      // just move
    } else {
      // even
    }
  }

  /// Compare difference
  int caculateDifferent(string original, string input) {
    int size = original.size();
    int endIndex = (size % 2 == 0) ? (size / 2 - 1) : (size / 2);
    int currentDiff = 0;
    for (int i = endIndex; i < size; i++) {
      int diff = abs(original[i] - input[i]);
      currentDiff = currentDiff * 10 + diff;
    }
    return currentDiff;
  }

  /// Compare number
  bool smaller(string a, string b) {
    for (int i = 0; i < a.size(); i++) {
      if (a[i] < b[i]) {
        return true;
      }
    }
    return false;
  }
};