 struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        int totalCount = 0;
        ListNode * current = head->next;
        if (current == nullptr) {
            return head;
        }
        while (current != head) {
            totalCount++;
            if (current->next == nullptr) {
                current->next = head;
            }
            current = current->next;
        }
        int breakCount = totalCount - (k % totalCount);
        for (int i = 1; i <= breakCount; i++) {
            if (i == breakCount) {
                ListNode * header = current->next;
                current->next = nullptr;
                return header;
            }
            current = current->next;
        }
        return nullptr;
    }
};