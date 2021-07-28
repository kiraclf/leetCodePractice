#include <set>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
 public:
  ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    set<ListNode *> cache;
    while (headA != nullptr || headB != nullptr) {
      if (headA == nullptr) { // headB exist
        if (cache.find(headB) == cache.end()) {
          cache.insert(headB);
          headB = headB->next;
        } else {
          return headB;
        }
      } else if (headB == nullptr) { // headA exist
        if (cache.find(headA) == cache.end()) {
          cache.insert(headA);
          headA = headA->next;
        } else {
          return headA;
        }
      } else { // both exist
      if (headA == headB) {
        return headA;
      } else if (cache.find(headA) != cache.end()) {
        return headA;
      } else if (cache.find(headB) != cache.end()) {
        return headB;
      } else {
        cache.insert(headA);
        cache.insert(headB);
        headA = headA->next;
        headB = headB->next;
      }
      }
    }
    // Find nothing.
    return nullptr;    
  }
};