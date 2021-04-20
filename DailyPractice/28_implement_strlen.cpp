#include <string>
#include <vector>
using namespace std;

class Solution {
 public:
  int strStr(string haystack, string needle) {
    // Empty needle handle.
    if (needle.length() == 0) {
      return 0;
    }
    // Create needle cache.
    int needleSize = needle.size();
    vector<int> needleCache(needleSize, 0);
    int cacheIndex = 1;
    int currentIndex = 0;
    while (cacheIndex < needleSize) {
      if (needle[currentIndex] == needle[cacheIndex]) {
        currentIndex++;
        needleCache[cacheIndex] = currentIndex;
        cacheIndex++;
      } else {
        if (currentIndex == 0) {
          cacheIndex++;
        } else {
          currentIndex = needleCache[currentIndex - 1];
        }
      }
    }
    // Search.
    int hayIndex = 0;
    int needleIndex = 0;
    while (hayIndex < haystack.size()) {
      if (haystack[hayIndex] == needle[needleIndex]) {
        if (needleIndex == needleSize - 1) {
          // Find match.
          return hayIndex - (needleSize - 1);
        } else {
          hayIndex++;
          needleIndex++;
        }
      } else {
        // Not match
        if (needleIndex == 0) {
          hayIndex++;
        } else {
          needleIndex = needleCache[needleIndex - 1];
        }
      }
    }
    // Not found.
    return -1;
  }
};

int main() {
  Solution solve;
  int result = solve.strStr("", "");
  return 0;
}