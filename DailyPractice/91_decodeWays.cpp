#include <vector>
#include <string>
using namespace std;
class Solution {
 public:
  int numDecodings(string s) {
    int size = s.size();
    // Exception handler
    if (size == 0) {
      return 0;
    }
    vector<int> cache(size, 1);
    for (int i = 1; i < size; i++) {
      int current = s[i] - 'A' + 1;
      int before = s[i-1] - 'A' + 1;
      if (current == 0) {
        cache[i] = cache[i-2];
      } else if (current >= 7) {
        cache[i] = cache[i-1];
      } else {
        if (before == 0) {
          cache[i] = cache[i-1];
        } else if (before > 2) {
          cache[i] = cache[i-1];
        } else {
          if (i - 2 >= 0) {
            cache[i] = cache[i - 1] + cache[i - 2];
          } else {
            cache[i] = cache[i-1] + 1;
          }
        }
      }
    }
    return cache[size - 1];
  }
};

int main() {
  Solution solve;
  int result = solve.numDecodings("0");
  return 0;
}