#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
 public:
  int distributeCandies(vector<int>& candyType) {
    // key-candyType : value-count
    unordered_map<int, int> candyMap;
    for (int i = 0; i < candyType.size(); i++) {
      candyMap[candyType[i]]++;
    }
    int totalType = 0;
    int totalCount = 0;
    for (auto pair : candyMap) {
      totalType += 1;
      totalCount += pair.second;
    }
    int targetCount = totalCount >> 1;
    if (totalType > targetCount) {
      return targetCount;
    }
    return totalType;
  }
};