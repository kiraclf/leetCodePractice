#include <unordered_map>
#include <vector>
using namespace std;
static const int kMaxCapacity = 200000;
class RandomizedSet {
 private:
  vector<int> numbers;
  unordered_map<int, int> map;
  int validIdx;

 public:
  RandomizedSet() {
    srand((unsigned)time(NULL));
    numbers = vector<int>(kMaxCapacity, 0);
    map = unordered_map<int, int>();
    validIdx = -1;
  }

  bool insert(int val) {
    if (map.find(val) != map.end()) {
      return false;
    }
    validIdx += 1;
    numbers[validIdx] = val;
    map[val] = validIdx;
    return true;
  }

  bool remove(int val) {
    if (map.find(val) == map.end()) {
      return false;
    }
    int index = map[val];
    if (index != validIdx) {
      numbers[index] = numbers[validIdx];
      map[numbers[index]] = index;
    }
    map.erase(val);
    validIdx--;
    return true;
  }

  int getRandom() {
    int index = rand() % (validIdx + 1);
    return numbers[index];
  }
};

int main() {
  auto set = RandomizedSet();
  set.remove(0);
  set.insert(0);
  int random = set.getRandom();
  set.remove(0);
  bool re = set.insert(0);
  return 0;
}