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
  vector<ListNode *> splitListToParts(ListNode *head, int k) {
    vector<int> countList(k, 0);
    getListLength(head, countList, k);
    ListNode *current = head;
    vector<ListNode *> res(k, {});
    for (int i = 0; i < countList.size(); i++) {
      if (current == nullptr) {
        break;
      }
      res[i] = current;
      int size = countList[i];
      int currentSize = 1;
      while (current != nullptr && currentSize <= size) {
        current = current->next;
        currentSize++;
      }
    }
    return res;
  }

  void getListLength(ListNode *head, vector<int> &listLength,int k) {
   vector<vector<ListNode *>> stack(k, {});
   ListNode * current = head;
   int index = 0;
   while (current != nullptr) {
     stack[index].push_back(current);
     current = current -> next;
     index = (index + 1) % k;
   }
   for (int i = 0; i < listLength.size(); i++) {
     listLength[i] = stack[i].size();
   }
  }
};


