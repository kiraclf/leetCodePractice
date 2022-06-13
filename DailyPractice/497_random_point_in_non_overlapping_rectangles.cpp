#include <vector>
using namespace std;
class Solution {
 private:
  vector<vector<int>> rects;
  vector<int> rectSpaces;
  int totalSpaces;

 public:
  Solution(vector<vector<int>>& rects) {
    // get each space count
    vector<int> rectSpaces(rects.size(), 0);
    int totalSpace = 0;
    for (int i = 0; i < rects.size(); i++) {
      int space = (rects[i][2] - rects[i][0]) * (rects[i][3] - rects[i][1]);
      rectSpaces[i] = space;
      totalSpace += space;
    }
    this->totalSpaces = totalSpace;
    this->rects = rects;
    this->rectSpaces = rectSpaces;
  }
  vector<int> pick() {
    int randNumber = rand() % totalSpaces + 1;
    int rectIndex = 0;
    int currentSpace = 0;
    for (int i = 0; i < rectSpaces.size(); i++) {
      rectIndex = i;
      if (currentSpace + rectSpaces[i] >= randNumber) {
        break;
      } else {
        currentSpace += rectSpaces[i];
      }
    }
    vector<int> rectStart = {rects[rectIndex][0], rects[rectIndex][1]};
    int width = rects[rectIndex][2] - rects[rectIndex][0];
    int height = rects[rectIndex][3] - rects[rectIndex][1];
    int xRand = rand() % (width + 1) + rectStart[0];
    int yRand = rand() % (height + 1) + rectStart[1];
    return {xRand, yRand};
  }
};