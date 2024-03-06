

struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
  ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode *p1, *p2, s;
    s.next = head;
    p1 = &s;
    for (int i = 0; i < n; i++) {
      p1 = p1->next;
    }
    p2 = &s;
    while (true) {
      p1 = p1->next;
      if (p1 == nullptr)
        break;
      p2 = p2->next;
    }
    p2->next = p2->next->next;
    return s.next;
  }
};
