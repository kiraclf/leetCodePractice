#include <vector>
using namespace std;

/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than
 * a nested list. bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a
 * single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a
 * nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedInteger {
  public:
    bool isInteger() const;
    int getInteger() const;
    const vector<NestedInteger> &getList() const;
};

class NestedIterator {
 public:
  NestedIterator(vector<NestedInteger> &nestedList) {
    dfs(nestedList);
    cur = vals.begin();
  }

  int next() {
    return *cur++;
  }

  bool hasNext() {
    return cur != vals.end();
  }
 private:
  vector<int> vals;
  vector<int>::iterator cur;

  void dfs(const vector<NestedInteger> &nestedList) {
    for (auto &nest : nestedList) {
      if (nest.isInteger()) {
        vals.push_back(nest.getInteger());
      } else {
        dfs(nest.getList());
      }
    }
  }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */