#include <queue>

class RecentCounter {
 private:
  std::queue<int> cache = {};
  void refreshCache(int time) {
    int earliestTime = time - 3000;
    while (cache.size() != 0) {
      int top = cache.front();
      if (top < earliestTime) {
        cache.pop();
      } else {
        break;
      }
    }
  }

 public:
  RecentCounter() {}
  int ping(int t) {
    cache.push(t);
    refreshCache(t);
    return cache.size();
  }
};