#include <vector>
using namespace std;


struct ListNode {
  int val;
  ListNode * next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
 public:
  ListNode* getKthFromEnd(ListNode* head, int k) {
    if (head == nullptr) {
      return nullptr;
    }
    ListNode * current = head;
    for (int i = 0; i < k; i++) {
      if (current == nullptr) {
        return nullptr;
      }
      current = (i == 0) ? head : current->next;
    }
    while (current != nullptr) {
      current = current->next;
      head = head->next;
    }
    return head;
  }
};
