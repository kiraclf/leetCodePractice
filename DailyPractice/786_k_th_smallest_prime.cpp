#include <queue>
#include <vector>
using namespace std;
struct Element {
  int i;
  int j;
  double value;
  Element(int i, int j, double value) : i(i), j(j), value(value) {}
  bool operator<(const Element& element) const {
    return (this->value < element.value);
  }
  bool operator>(const Element& element) const { return !((*this) < element); }
};
class Solution {
 public:
  vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
    priority_queue<Element, vector<Element>, less<Element>> queue;
    for (int i = 0; i < arr.size() - 1; i++) {
      for (int j = i + 1; j < arr.size(); j++) {
        if (queue.size() < k) {
          queue.push(Element(i, j, (float)arr[i] / (float)arr[j]));
        } else {
          Element top = queue.top();
          Element current = Element(i, j, (float)arr[i] / (float)arr[j]);
          if (current < top) {
            queue.pop();
            queue.push(current);
          }
        }
      }
    }
    Element result = queue.top();
    vector<int> res = {arr[result.i], arr[result.j]};
    return res;
  }
};

int main() {
  Solution solution;
  vector<int> test = {1, 2, 3, 5};
  int k = 3;
  auto res = solution.kthSmallestPrimeFraction(test, k);
  return 0;
}
