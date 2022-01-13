#include <vector>
using namespace std;
class Solution {
 public:
  char slowestKey(vector<int>& releaseTimes, string keysPressed) {
    int beforeTime = 0;
    int longestDuration = 0;
    char key = '0';
    for (int i = 0; i < releaseTimes.size(); i++) {
      int duration = releaseTimes[i] - beforeTime;
      beforeTime = releaseTimes[i];
      if (duration >= longestDuration) {
        if (duration > longestDuration) {
          longestDuration = duration;
          key = keysPressed[i];
        } else {
          if (keysPressed[i] > key) {
            key = keysPressed[i];
          }
        }
      }
    }
    return key;
  }
};