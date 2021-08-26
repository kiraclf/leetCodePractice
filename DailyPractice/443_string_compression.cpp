#include <string>
#include <vector>
using namespace std;
class Solution {
 public:
  int compress(vector<char>& chars) {
    if (chars.size() <= 1) {
      return chars.size();
    }
    int totalSize = chars.size();
    int startIndex = 1;
    int duplicateCount = 1;
    while (startIndex < totalSize) {
      if (chars[startIndex] != chars[startIndex - 1]) {
        writeNumberToList(chars[startIndex-1], duplicateCount, chars);
        duplicateCount = 1;
      } else {
        duplicateCount++;
      }
      startIndex++;
    }
    writeNumberToList(chars[totalSize-1], duplicateCount, chars);
    chars.erase(chars.begin(), chars.begin() + totalSize);
    return chars.size();
  }

  void writeNumberToList(char duplicateChar, int count, vector<char>& chars) {
    chars.push_back(duplicateChar);
    int currentSize = chars.size();
    if (count == 1) {
      return;
    } else {
      while (count != 0) {
        chars.push_back( '0' + count % 10);
        count /= 10;
      }
      int size = chars.size();
      reverse(chars.end()-(size - currentSize), chars.end());
    }
  }
};

int main() {
  Solution solve;
  vector<char> test = {'a', 'a', 'b', 'b', 'c', 'c'};
  int result = solve.compress(test);
  return 0;
}