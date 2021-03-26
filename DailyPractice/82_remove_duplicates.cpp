#include <vector>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0),next(nullptr){}
  ListNode(int x): val(x),next(nullptr){}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
 public:
  ListNode* deleteDuplicates(ListNode* head) {
    ListNode * dummyHead = new ListNode(-101);
    ListNode * beforeNode = dummyHead;
    ListNode * lastRemovedNode = nullptr;
    dummyHead->next = head;
    ListNode * current = head;
    while (current != nullptr) {
      ListNode * nextNode = current->next;
      if (lastRemovedNode != nullptr && lastRemovedNode->val == current->val) {
        beforeNode->next = current->next;
        current = current->next;
        continue;
      }
      if (current->next != nullptr && nextNode->val == current->val) {
        // duplicate, remove all
        beforeNode->next = nextNode->next;
        lastRemovedNode = current;
        current = nextNode->next;
        continue;
      }
      beforeNode = current;
      current = current->next;
    }
    return dummyHead->next;
  }
};