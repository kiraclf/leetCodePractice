using namespace std;

struct ListNode {
  int val;
  ListNode* next;
  ListNode()
      : val(0),
  next(nullptr){}ListNode(int x)
      : val(x),
  next(nullptr){}ListNode(int x, ListNode* next) : val(x), next(next){}
};
class Solution {
 public:
  ListNode* reverseBetween(ListNode* head, int left, int right) {
    ListNode * startBeforeNode;
    ListNode * startNode;
    ListNode * endAfterNode;
    ListNode * endNode;
    ListNode * current = head;
    int start = 1;
    // seek start posistion
    while (start <= left) {
      if (start == left - 1) {
        startBeforeNode = current;
      }
      if (start == 1) {
        start++;
        continue;
      } else {
        current = current->next;
      }
      start++;
    }
    start--;
    startNode = current;
    ListNode * reverseStart = revreseNode(startNode, right - left + 1, startBeforeNode);
    if (startBeforeNode != nullptr) {
      return head;
    } else {
      return reverseStart;
    }
  }

  ListNode * revreseNode(ListNode * head, int size, ListNode * startBeforeNode) {
    int count = 0;
    ListNode * current = head;
    ListNode * beforeNode = nullptr;
    ListNode * lastNode = nullptr;
    while (count < size && current != nullptr) {
      ListNode * next = current->next;
      current->next = beforeNode;
      beforeNode = current;
      current = next;
      count++;
      if (count == size) {
        head->next = current;
        if (startBeforeNode != nullptr) {
          startBeforeNode->next = beforeNode;
        }
      }
    }
    return beforeNode;
  }
};

int main() {
}