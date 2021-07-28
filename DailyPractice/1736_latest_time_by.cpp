#include <string>
#include <vector>
using namespace std;
class Solution {
 public:
  string maximumTime(string time) {
    vector<char> possibleMax = {'2', '3', ':', '5', '9'};
    for (int i = 0; i < time.size(); i++) {
      if (time[i] == '?') {
        time[i] = possibleMax[i];
      }
    }
    return time;
  }
};