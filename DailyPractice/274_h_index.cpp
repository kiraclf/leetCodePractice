#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
 public:
  int hIndex(vector<int>& citations) {
    sort(citations.begin(), citations.end());
    int maxCitations = citations[citations.size() - 1];
    int startIndex = 0;
    int endIndex = citations.size() - 1;
    while (startIndex <= endIndex) {
      int midIndex = startIndex + (endIndex - startIndex) / 2;
      int h = citations[midIndex];
      int count = citations.size() - midIndex;
      if ( h >= count) { // h 过高
        endIndex = midIndex - 1;
      } else {
        startIndex = midIndex + 1;
      }
    }
    return citations.size() - startIndex;
  }
};

int main() {
  Solution solve;
  vector<int> test = {1,3,1};
  int result = solve.hIndex(test);
  return 0;
}