#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Solution {
 public:
  string pushDominoes(string dominoes) {
    // get left and right indexs from start to end.
    vector<int> LAndRIndexs;
    for (int i = 0; i < dominoes.size(); i++) {
      if (dominoes[i] == 'L' || dominoes[i] == 'R') {
        LAndRIndexs.push_back(i);
      }
    }
    // zero result.
    if (LAndRIndexs.size() == 0) {
      return dominoes;
    }
    string result = dominoes;
    // handle leading and trailing
    char firstChar = dominoes[LAndRIndexs[0]];
    char lastChar = dominoes[LAndRIndexs[LAndRIndexs.size() - 1]];
    for (int i = 0; i <= LAndRIndexs[0]; i++) {
      if (firstChar == 'L') {
        result[i] = firstChar;
      }
    }
    for (int i = LAndRIndexs[LAndRIndexs.size() - 1]; i < dominoes.size();
         i++) {
      if (lastChar == 'R') {
        result[i] = lastChar;
      }
    }
    if (dominoes.size() == 1) {
      return result;
    }
    // handle middle.
    for (int i = 1; i < LAndRIndexs.size(); i++) {
      if (dominoes[LAndRIndexs[i]] == dominoes[LAndRIndexs[i - 1]]) {
        // same
        for (int j = LAndRIndexs[i - 1]; j <= LAndRIndexs[i]; j++) {
          result[j] = dominoes[LAndRIndexs[i]];
        }
      } else {
        // not same
        if (dominoes[LAndRIndexs[i]] == 'R') {
          continue;
        }
        int totalCount = LAndRIndexs[i] - LAndRIndexs[i - 1] + 1;
        int eachCount = totalCount / 2;
        for (int j = LAndRIndexs[i - 1]; j < LAndRIndexs[i - 1] + eachCount;
             j++) {
          result[j] = dominoes[LAndRIndexs[i - 1]];
        }
        for (int j = LAndRIndexs[i]; j > LAndRIndexs[i] - eachCount; j--) {
          result[j] = dominoes[LAndRIndexs[i]];
        }
      }
    }
    return result;
  }
};

int main() {
  Solution solve;
  vector<string> toTest = {"RR.L", ".L.R...LR..L.."};
  for (auto &test : toTest) {
    string res = solve.pushDominoes(test);
    cout << "start point: " << test << "/n"
         << "end point: " << res << endl;
  }
  return 0;
}