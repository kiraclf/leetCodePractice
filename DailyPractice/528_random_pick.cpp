#include <vector>
#include <random>
using namespace std;
class Solution {
 private:
  vector<long long> start;
  long long total;
 public:
  Solution(vector<int>& w) {
    start = vector<long long>(w.size(), 0);
    long long sum = 0;
    for (auto weight : w) {
      sum += (long long) weight;
    }
    for (int i = 1; i < w.size(); i++) {
      start[i] = start[i - 1] + (long long)w[i - 1];
    }
    total = sum;
  }
  int pickIndex() {
    random_device rd;
    default_random_engine generator(rd());
    uniform_int_distribution<long long> distribution(0, total);
    long long randomNubmer = distribution(generator);
    int startIndex = 0;
    int endIndex = start.size() - 1;
    int selectedIndex = -1;
    while (startIndex <= endIndex) {
      int midIndex = startIndex + (endIndex - startIndex) / 2;
      if (start[midIndex] > randomNubmer) {
        endIndex = midIndex - 1;
      } else {
        selectedIndex = midIndex;
        startIndex = midIndex + 1;
      }
    }
    return selectedIndex;
  }
};