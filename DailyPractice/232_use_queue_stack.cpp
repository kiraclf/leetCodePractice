#include <vector>
using namespace std;
class MyQueue {
 public:
  /** Initialize your data structure here. */
  MyQueue() {
    queue = vector<int>();
    backQueue = vector<int>();
  }

  /** Push element x to the back of queue. */
  void push(int x) {
    queue.push_back(x);
  }

  /** Removes the element from in front of queue and returns that element. */
  int pop() {
    if (empty()) {
      return 0;
    }
    if (backQueue.size() > 0) {
      int value = backQueue.back();
      backQueue.pop_back();
      return value;
    } else {
      transferQueue();
      return pop();
    }
  }

  /** Get the front element. */
  int peek() {
    if (empty()) {
      return 0;
    }
    if (backQueue.size() > 0) {
      return backQueue.back();
    } else {
      transferQueue();
      return peek();
    }
  }

  /** Returns whether the queue is empty. */
  bool empty() {
    return queue.size() == 0 && backQueue.size() == 0;
  }
private:
  vector<int> queue;
  vector<int> backQueue;

  void transferQueue() {
    while (queue.size() != 0) {
      int value = queue.back();
      backQueue.push_back(value);
      queue.pop_back();
    }
  }
};