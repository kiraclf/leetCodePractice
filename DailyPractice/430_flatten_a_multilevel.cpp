#include <vector>
using namespace std;

class Node {
  public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};

class Solution {
 public:
  Node* flatten(Node* head) {
    // create dummy head
    Node* _head = new Node();
    _head->next = head;
    vector<Node*> parentStack;
    recursiveFlatten(head, _head, parentStack);
    return _head->next;
  }

  void recursiveFlatten(Node* current, Node* before, vector<Node*>& parent) {
    // terminate
    if (current == nullptr) {
      if (parent.size() == 0) {
        return;
      }
      before->next = parent[parent.size() - 1];
      parent[parent.size() - 1]->prev = before;
      parent.pop_back();
      recursiveFlatten(before->next, before, parent);
      return;
    }
    // child
    if (current->child != nullptr) {
      if (current->next != nullptr) {
        parent.push_back(current->next);
      }
      current->next = current->child;
      current->child->prev = current;
      current->child = nullptr;
      recursiveFlatten(current->next, current, parent);
    }
    // next
    recursiveFlatten(current->next, current, parent);
  }
};

int main() {
  Solution solve;
  Node* one = new Node{1, nullptr, nullptr, nullptr};
  Node* two = new Node{2, nullptr, nullptr, nullptr};
  Node* three = new Node{3, nullptr, nullptr, nullptr};
  Node* four = new Node{4, nullptr, nullptr, nullptr};
  Node* five = new Node{5, nullptr, nullptr, nullptr};
  Node* six = new Node{6, nullptr, nullptr, nullptr};
  Node * sevent = new Node{7, nullptr, nullptr, nullptr};
  Node * eight = new Node{8, nullptr, nullptr, nullptr};
  Node * nine = new Node{9, nullptr, nullptr, nullptr};
  Node * ten = new Node{10, nullptr, nullptr, nullptr};
  Node * oneone = new Node{11, nullptr, nullptr, nullptr};
  Node * twelve = new Node{12, nullptr, nullptr, nullptr};
  one->child = two;
  two->prev = one;
  one->next = two;
  two->prev = one;
  Node* formatted = solve.flatten(one);
  return 0;
}