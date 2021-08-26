#include <vector>
#include <unordered_set>
using namespace std;
class Solution {
 public:
  int numRescueBoats(vector<int>& people, int limit) {
    if (people.size() == 0) {
      return 0;
    }
    sort(people.begin(), people.end());
    unordered_set<int> visited;
    int currentIndex = people.size() - 1;
    int boatCount = 0;
    while (currentIndex >= 0) {
     if (visited.find(currentIndex) != visited.end()) {
       currentIndex--;
       continue;
     }
     int companyIndex = findMaxIndex(people, visited, limit, currentIndex);
     if (companyIndex == -1) {
       visited.insert(currentIndex);
       boatCount++;
       currentIndex--;
     } else {
       visited.insert(currentIndex);
       visited.insert(companyIndex);
       boatCount++;
       currentIndex--;
     }
    }
    return boatCount;
  }

  /// 找不到返回 -1 , 否则返回对应的 index
  int findMaxIndex(vector<int>& people, unordered_set<int>& visited, int limit, int currentIndex) {
    int currentValue = people[currentIndex];
    int companyIndex = -1;
    int startIndex = 0;
    int endIndex = currentIndex - 1;
    while (startIndex <= endIndex) {
      int midIndex = startIndex + (endIndex - startIndex) / 2;
      if (people[midIndex] + currentValue <= limit) {
        companyIndex = midIndex;
        startIndex = midIndex + 1;
      } else {
        endIndex = midIndex - 1;
      }
    }
    while (companyIndex != -1 && visited.find(companyIndex) != visited.end()) {
      companyIndex--;
    }
    return companyIndex;
  }
};

int main() {
  Solution solve;
  vector<int> people = {3,2,2,1};
  int boatCount = solve.numRescueBoats(people, 3);
  return 0;
}