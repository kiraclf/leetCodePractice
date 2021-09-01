#include <string>
#include <vector>
using namespace std;
class Solution {
 public:
  int compareVersion(string version1, string version2) {
    if (version1.size() == 0 || version2.size() == 0) {
      return -2;
    }
    int firstIndex = 0;
    int secondIndex = 0;
    while (firstIndex < version1.size() || secondIndex < version2.size()) {
      int firstValue = 0;
      int secondValue = 0;
      if (firstIndex < version1.size()) {
        firstValue = getComponentValue(version1, firstIndex);
      }
      if (secondIndex < version2.size()) {
        secondValue = getComponentValue(version2, secondIndex);
      }
      if (firstValue > secondValue) {
        return 1;
      } else if (firstValue < secondValue) {
        return -1;
      }
    }
    return 0;
  }

  int getComponentValue(string version, int& index) {
    int currentValue = 0;
    while (index < version.size() && version[index] != '.') {
      currentValue = (currentValue)*10 + (int)(version[index] - '0');
      index++;
    }
    if (index < version.size() && version[index] == '.') {
      index++;
    }
    return currentValue;
  }
};

int main() {
  string version1 = "1.0.0.4";
  string version2 = "1.0.0";
  Solution solve;
  int result = solve.compareVersion(version1, version2);
  return 0;
}