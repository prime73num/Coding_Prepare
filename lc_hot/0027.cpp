struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
  ListNode* swapPairs(ListNode* head) {
    if(head == nullptr)
      return head;
    ListNode s;
    s.next = head;

    ListNode* p = &s;
    while (true) {
      ListNode* prev = nullptr;
      ListNode* temp = p;
      p = p->next;
      for(int i = 0; i<2 && p != nullptr; i++){
        ListNode* next = p->next;
        p->next = prev;
        prev = p;
        p = next;
      }
      ListNode* tail = temp->next;
      tail->next = p;
      temp->next = prev;
      if(p==nullptr)
        break;
      p = tail;
    }
    return s.next;
  }
};
