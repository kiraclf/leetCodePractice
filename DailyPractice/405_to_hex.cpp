#include <cmath>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
 public:
  string toHex(int num) {
    if (num == 0) {
      return "0";
    }
    // init map
    unordered_map<int, char> map;
    for (int i = 0; i < 10; i++) {
      map[i] = '0' + i;
    }
    for (int i = 10; i < 16; i++) {
      map[i] = 'a' + i - 10;
    }
    // process
    if (num < 0) {
      int top = 1;
      while ((num + top * pow(16, 7)) < 0) {
        top++;
      }
      return toHexPosNum(true, num + top * pow(16, 7), map, top);
    }
    return toHexPosNum(false, num, map, 0);
  }

  string toHexPosNum(bool negative, int num, unordered_map<int, char>& map,
                     int top) {
    string res;
    while (num != 0) {
      int value = num % 16;
      char character = map[value];
      res.push_back(character);
      num = num / 16;
    }
    reverse(res.begin(), res.end());
    if (!negative) {
      return res;
    } else {
      while (res.size() < 7) {
        res.insert(res.begin(), '0');
      }
      res.insert(res.begin(), map[top]);
      return res;
    }
  }
};

int main() {
  Solution solve;
  string res = solve.toHex(-1);
  return 0;
}