#include <map>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;
class TimeMap {
 public:
  /** Initialize your data structure here. */
  TimeMap() { 
    cache = unordered_map<string, vector<pair<int, string>>>(); 
    }
  void set(string key, string value, int timestamp) {
    pair<int, string> current = {timestamp, value};
    cache[key].push_back(current);
  }
  string get(string key, int timestamp) {
    if (cache.find(key) == cache.end()) {
      return "";
    }
    vector<pair<int, string>> currentKeyCache = cache[key];
    if (currentKeyCache.size() == 0) {
      return "";
    }
    int startIndex = 0;
    int endIndex = currentKeyCache.size() - 1;
    while (startIndex < endIndex) {
      int mid = startIndex + (endIndex - startIndex) / 2;
      int midValue = currentKeyCache[mid].first;
      if (midValue == timestamp) {
        return currentKeyCache[mid].second;
      } else if (midValue < timestamp) {
        startIndex = mid + 1;
      } else {
        endIndex = mid - 1;
      }
    }
    return currentKeyCache[startIndex].second;
  }

 private:
  unordered_map<string, vector<pair<int, string>>> cache;
};