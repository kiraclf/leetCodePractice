#include <string>
using namespace std;
class Solution {
 public:
  string toLowerCase(string s) {
    int differ = 'a' - 'A';
    for (int i = 0; i < s.size(); i++) {
      if (s[i] >= 'A' && s[i] <= 'Z') {
        s[i] = differ + s[i];
      }
    }
    return s;
  }
};