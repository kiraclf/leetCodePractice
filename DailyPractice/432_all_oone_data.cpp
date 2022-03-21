#include <string>
#include <unordered_map>
using namespace std;
class AllOne {
 private:
  unordered_map<string, int> storage;
  string maxKey;
  string minKey;

 public:
  AllOne() {
    storage = {};
    maxKey = "";
    minKey = "";
  }
  void inc(string key) {
    storage[key] += 1;
    // max handle
    if (maxKey == "") {
      maxKey = key;
    } else if (storage[key] > storage[maxKey]) {
      maxKey = key;
    }
    // min handle
    if (minKey == "") {
      minKey = key;
    }
  }
  void dec(string key) {
    storage[key] -= 1;
    // 0 count handler
    if (storage[key] == 0 && minKey == key) {
    } else if (storage[minKey] > storage[key]) {
      minKey = key;
    }
  }
  string getMaxKey() { return maxKey; }
  string getMinKey() { return minKey; }
};