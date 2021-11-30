#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
 public:
  string originalDigits(string s) {
    // number string vector
    vector<string> numberStrings = {"zero", "one", "two",   "three", "four",
                                    "five", "six", "seven", "eight", "nine"};
    unordered_map<int, vector<int>> numberCache;
    for (int i = 0; i < 10; i++) {
      vector<int> digitCount(26, 0);
      for (int j = 0; j < numberStrings[i].size(); j++) {
        digitCount[numberStrings[i][j] - 'a'] += 1;
      }
      numberCache[i] = digitCount;
    }
    // s number
    int totalSize = s.size();
    vector<int> sNumber(26, 0);
    for (int i = 0; i < totalSize; i++) {
      sNumber[s[i] - 'a'] += 1;
    }
    // generate result
    string ans = "";
    // process
    while (totalSize != 0) {
      for (int i = 0; i < 10; i++) {
        vector<int> patternString = numberCache[i];
        bool match = true;
        for (int j = 0; j < 26; j++) {
          if (patternString[j] > sNumber[j]) {
            match = false;
            break;
          }
        }
        if (match) {
          ans += to_string(i);
          for (int j = 0; j < 26; j++) {
            sNumber[j] -= patternString[j];
            totalSize -= patternString[j];
          }
          break;
        }
      }
    }
    return ans;
  }

  /// 根据各个字符串中的唯一性,进行枚举.
  ///
  /// * z 只在 zero 中出现,因此可以优先统计(类似....)
  string originalDigitsOfficalAnswer(string s) {
    unordered_map<char, int> c;
    for (char ch : s) {
      ++c[ch];
    }

    vector<int> cnt(10);
    cnt[0] = c['z'];
    cnt[2] = c['w'];
    cnt[4] = c['u'];
    cnt[6] = c['x'];
    cnt[8] = c['g'];

    cnt[3] = c['h'] - cnt[8];
    cnt[5] = c['f'] - cnt[4];
    cnt[7] = c['s'] - cnt[6];

    cnt[1] = c['o'] - cnt[0] - cnt[2] - cnt[4];

    cnt[9] = c['i'] - cnt[5] - cnt[6] - cnt[8];

    string ans;
    for (int i = 0; i < 10; ++i) {
      for (int j = 0; j < cnt[i]; ++j) {
        ans += char(i + '0');
      }
    }
    return ans;
  };

  int main() {
    Solution solve;
    string test = "fviefuro";
    string result = solve.originalDigits(test);
    return 0;
  }