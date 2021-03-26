#include <vector>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
 public:
  ListNode* deleteDuplicates(ListNode* head) {
    ListNode * dummyHead = new ListNode(101);
    dummyHead->next = head;
    ListNode * current = head;
    ListNode * before = dummyHead;
    while (current != nullptr) {
      if (current->val == before->val) {
        current = current->next;
        before->next = current;
      } else {
        before = current;
        current = current->next;
      }
    }
    return dummyHead->next;
  }
};