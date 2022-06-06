#include <vector>
using namespace std;
class Appointment {
 public:
  int start;
  int end;
  int count;
  int add;
  Appointment* left;
  Appointment* right;
  Appointment(int start, int end, int max, int add, Appointment* left,
              Appointment* right)
      : start(start),
        end(end),
        count(max),
        add(add),
        left(left),
        right(right) {}
};

static const int kMaxTime = 1000000000;
class MyCalendarThree {
  Appointment* root;
  int maxCount;

 public:
  MyCalendarThree() {
    root = new Appointment(0, kMaxTime, 0, 0, nullptr, nullptr);
    maxCount = 0;
  }
  int book(int start, int end) {
    addNode(start, end - 1, 1, root);
    return maxCount;
  }
  void addNode(int start, int end, int count, Appointment* node) {
    int mid = node->start + (node->end - node->start) / 2;
    if (start == (node->start) && end == node->end) {
      updateValue(node, 1);
      return;
    }
    if (end <= mid) {
      // go to left
      lazyGenerateNode(node);
      addNode(start, end, count, node->left);
    } else if (start > mid) {
      // go to right
      lazyGenerateNode(node);
      addNode(start, end, count, node->right);
    } else {
      // divide
      int firstLeft = start;
      int firstRight = mid;
      int secondLeft = mid + 1;
      int secondRight = end;
      lazyGenerateNode(node);
      addNode(firstLeft, firstRight, count, node->left);
      addNode(secondLeft, secondRight, count, node->right);
    }
  }

  void updateValue(Appointment* node, int count) {
    node->count += count;
    this->maxCount = max(node->count, this->maxCount);
    if (node->left == nullptr) {
      node->add += count;
    } else {
      updateValue(node->left, count);
      updateValue(node->right, count);
    }
  }

  void lazyGenerateNode(Appointment* node) {
    if (node->left != nullptr || node->start == node->end) {
      return;
    }
    int mid = node->start + (node->end - node->start) / 2;
    Appointment* left = new Appointment(node->start, mid, node->add, node->add,
                                        nullptr, nullptr);
    Appointment* right = new Appointment(mid + 1, node->end, node->add,
                                         node->add, nullptr, nullptr);
    node->add = 0;
    node->left = left;
    node->right = right;
  }
};

int main() {
  MyCalendarThree tree;
  vector<vector<int>> toTest = {{10, 20}, {50, 60}, {10, 40},
                                {5, 15},  {5, 10},  {25, 55}};
  vector<int> ans;
  for (auto test : toTest) {
    int result = tree.book(test[0], test[1]);
    ans.push_back(result);
  }
  return 0;
}