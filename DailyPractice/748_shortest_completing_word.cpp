#include <string>
#include <vector>
using namespace std;
class Solution {
 public:
  string shortestCompletingWord(string licensePlate, vector<string>& words) {
    vector<int> licencesMap(26, 0);
    for (auto licenseChar : licensePlate) {
      if (licenseChar >= 'A' && licenseChar <= 'Z') {
        licenseChar = licenseChar + 'a' - 'A';
      }
      if (licenseChar >= 'a' && licenseChar <= 'z') {
        licencesMap[licenseChar - 'a'] += 1;
      }
    }
    string possibleAns = "";
    int ansCount = -1;
    for (auto word : words) {
      vector<int> wordMap(26, 0);
      for (int i = 0; i < word.size(); i++) {
        char wordChar = word[i];
        wordMap[wordChar - 'a'] += 1;
      }
      bool match = true;
      for (int i = 0; i < 26; i++) {
        if (wordMap[i] < licencesMap[i]) {
          match = false;
          break;
        }
      }
      if (match) {
        if (ansCount == -1) {
          possibleAns = word;
          ansCount = word.size();
        } else if ((int)word.size() < ansCount) {
          possibleAns = word;
          ansCount = word.size();
        }
      }
    }
    return possibleAns;
  }
};

int main() {
  Solution solve;
  string plate = "1s3 456";
  vector<string> words = {"looks", "pest", "stew", "show"};
  string res = solve.shortestCompletingWord(plate, words);
  return 0;
}