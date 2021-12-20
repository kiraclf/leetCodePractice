#include <unordered_map>
#include <vector>
using namespace std;
class TopVotedCandidate {
 private:
  vector<int> times;
  vector<int> top;

 public:
  TopVotedCandidate(vector<int>& persons, vector<int>& times) {
    this->times = times;
    // create top
    vector<int> tops(persons.size(), 0);
    // generate sliced max
    int currentMaxCount = 1;
    int currentMaxValue = persons[0];
    tops[0] = persons[0];
    unordered_map<int, int> personCount;
    personCount[persons[0]] += 1;
    for (int i = 1; i < persons.size(); i++) {
      personCount[persons[i]] += 1;
      if (personCount[persons[i]] >= currentMaxCount) {
        currentMaxCount = personCount[persons[i]];
        currentMaxValue = persons[i];
      }
      tops[i] = currentMaxValue;
    }
    this->top = tops;
  }

  int q(int t) {
    int start = 0;
    int end = times.size() - 1;
    int targetIndex = -1;
    while (start <= end) {
      int mid = start + ((end - start) >> 1);
      int midTime = times[mid];
      if (midTime == t) {
        targetIndex = mid;
        break;
      } else if (midTime < t) {
        start = mid + 1;
      } else {
        end = mid - 1;
      }
    }
    targetIndex = targetIndex != -1 ? targetIndex : end;
    return top[targetIndex];
  }
};

int main() {
  vector<int> persons = {0, 1, 1, 0, 0, 1, 0};
  vector<int> times = {0, 5, 10, 15, 20, 25, 30};
  TopVotedCandidate* obj = new TopVotedCandidate(persons, times);
  vector<int> test = {3, 12, 25, 15, 24, 8};
  vector<int> res;
  for (int i = 0; i < test.size(); i++) {
    res.push_back(obj->q(test[i]));
  }
  return 0;
}