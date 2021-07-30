#include <unordered_map>
using namespace std;
class Node {
public:
  int val;
  Node* next;
  Node* random;

  Node(int _val) {
    val = _val;
    next = nullptr;
    random = nullptr;
  }
};

class Solution {
 public:
  Node* copyRandomList(Node* head) {
    if (head == nullptr) {
      return nullptr;
    }
    Node* newRoot = new Node(-1);
    unordered_map<Node*, Node*> nextMap;
    // head init.
    Node* current = head;
    Node* currentCopyed = new Node(current->val);
    nextMap[current] = currentCopyed;
    newRoot->next = currentCopyed;
    if (current->random != nullptr) {
      Node* next; 
      if (nextMap.find(current->random) != nextMap.end()) {
        next = nextMap[current->random];
      }
      else {
        next = new Node(current->random->val);
        nextMap[current->random] = next;
      }
      currentCopyed->random = next;
    }
    // list recusive.
    current = current->next;
    while (current != nullptr) {
      Node * created;
      if (nextMap.find(current) != nextMap.end()) {
        created = nextMap[current];
      } else {
        created = new Node(current->val);
        nextMap[current] = created;
      }
      if (current->random != nullptr) {
        Node* random;
        if (nextMap.find(current->random) != nextMap.end()) {
          random = nextMap[current->random];
        } else {
          random = new Node(current->random->val);
          nextMap[current->random] = random;
        }
        created->random = random;
      }
      currentCopyed->next = created;
      currentCopyed = created;
      current = current->next;
    }
    return newRoot->next;
  }
};

int main() {
  Solution solve;
  Node * root = new Node(-1);
  Node * next1 = new Node(13);
  Node * next2 = new Node(11);
  Node * next3 = new Node(10);
  Node * next4 = new Node(1);
  root->random = root;
  next1->next = next2;
  next2->next = next3;
  next3->next = next4;
  next1->random = next1;
  next3->random = next2;
  next1->random = root;
  next4->random = root;
  Node * head = solve.copyRandomList(root);
  return 0;
}