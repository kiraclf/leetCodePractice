#include <string>
using namespace std;
class Solution {
 public:
  string reverseStr(string s, int k) {
    if (s.size() == 0) {
      return "";
    }
    int startIndex = 0;
    int endIndex = 0;
    while (endIndex < s.size()) {
      if (endIndex == s.size() - 1 && (endIndex - startIndex + 1) < 2 * k && (endIndex - startIndex + 1) >= k) {
        // 翻转剩余的前k个字符
        reverseString(s, startIndex, startIndex + k - 1);
        break;
      } else if (endIndex == s.size() - 1 && (endIndex - startIndex + 1) < k) {
        // 翻转剩余的全部字符
        reverseString(s, startIndex, s.size() - 1);
        break;
      } else if (endIndex - startIndex + 1 == 2 * k) {
        // 翻转前k个
        reverseString(s, startIndex, startIndex + k - 1);
        startIndex = startIndex + 2*k;
        endIndex++;
      } else {
        // 向后移动 end
        endIndex++;
      }
    }
    return s;
  }

  void reverseString(string& s, int startIndex, int endIndex) {
    while (startIndex < endIndex) {
      char startChar = s[startIndex];
      s[startIndex] = s[endIndex];
      s[endIndex] = startChar;
      startIndex++;
      endIndex--;
    }
  }
};

int main() {
  Solution solve;
  string res = solve.reverseStr("abcdefg", 2);
  return 0;
}