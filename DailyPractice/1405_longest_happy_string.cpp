#include <string>
#include <unordered_map>
using namespace std;
class Solution {
 public:
  string longestDiverseString(int a, int b, int c) {
    string res = "";
    unordered_map<char, int> countMap;
    countMap['a'] = a;
    countMap['b'] = b;
    countMap['c'] = c;
    while (res.size() <= a + b + c) {
      // exception
      if (res.size() >= 2 && res[res.size() - 1] == res[res.size() - 2]) {
        bool canAdd = false;
        char toAddChar = -1;
        for (auto count : countMap) {
          if (count.first != res[res.size() - 1] && count.second > 0) {
            canAdd = true;
            if (toAddChar == -1) {
              toAddChar = count.first;
            } else {
              if (countMap[toAddChar] < count.second) {
                toAddChar = count.first;
              }
            }
          }
        }
        if (!canAdd) {
          break;
        } else {
          res.push_back(toAddChar);
          countMap[toAddChar] -= 1;
        }
      } else {
        char toAddChar = -1;
        for (auto count : countMap) {
          if (count.second > 0) {
            if (toAddChar == -1) {
              toAddChar = count.first;
            } else {
              if (countMap[toAddChar] < count.second) {
                toAddChar = count.first;
              }
            }
          }
        }
        if (toAddChar == -1) {
          break;
        } else {
          res.push_back(toAddChar);
          countMap[toAddChar] -= 1;
        }
      }
    }
    return res;
  }
};

int main() {
  Solution solve;
  string res = solve.longestDiverseString(1, 1, 7);
  return 0;
}