struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
 public:
  ListNode* removeElements(ListNode* head, int val) {
    ListNode * dummyHead = new ListNode(-1);
    dummyHead->next = head;
    ListNode * current = head;
    ListNode * before = dummyHead;
    while (current != nullptr) {
      if (current->val == val) {
        current = current->next;
        before->next = current;
      } else {
        before = current;
        current = current->next;
      }
    }
    ListNode * newHead = dummyHead->next;
    delete dummyHead;
    return newHead;
  }
};