/*
给你一个仅由大写英文字母组成的字符串
你可以将任意位置上的字符替换成另外的字符，总共可最多替换 k 次。
在执行上述操作后，找到包含重复字母的最长子串的长度。
注意：字符串长度 和 k 不会超过 104。
*/

/*
分析: 
  最长子串的长度最大为 s.size()
  二分搜索替换k个字符能否变成长度为k的重复子串
  确定了长度之后,可以每次直接看定长的字符 -> 统计字符内部各个字符的个数
*/
#include <vector>
#include <string>
using namespace std;
class Solution {
 public:
  int characterReplacement(string s, int k) {
    int length = s.length(), left = 1, right = length;
    if (length <= 1) {
      return length;
    }
    while (left <= right) {
      int mid = (right + left) / 2;
      bool changed = false;
      for (int i = 0; i <= length - mid; i++) {
        string subString = s.substr(i, mid);
        if (canReplaced(subString, k)) {
          left = mid + 1;
          changed = true;
          break;
        }
      }
      if (!changed) {
        right = mid - 1;
      }
    }
    return right;
  }

  bool canReplaced(string s, int k) {
    int size = s.length();
    vector<int> charCount(26, 0);
    for (auto character : s) {
      int index = character - 'A';
      charCount[index]++;
    }
    int maxCount = 0;
    for (auto value : charCount) {
      maxCount = max(value, maxCount);
    }
    int toReplaceCount = size - maxCount;
    return toReplaceCount <= k;
  }

  int slidingWindow(string s, int k) {
    int length = s.length(), left = 0, right = 0;
    if (length <= 1) {
      return length;
    }
    vector<int> charCount(26, 0);
    int historyCharMax = 0;
    for (; right < length; right++) {
      int index = s[right] - 'A';
      charCount[index]++;
      historyCharMax = max(historyCharMax, charCount[index]);
      if (right - left + 1 > historyCharMax + k) {
        charCount[s[left] - 'A']--;
        left++;
      }
    }
    return length - left;
  }
};

int main() {
  string s = "ABAB";
  Solution solve;
  int result = solve.characterReplacement(s, 2);
  return 0;
}