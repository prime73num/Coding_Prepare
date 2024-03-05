#include "stdc++.h"

struct ListNode {
  int val;
  ListNode* next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
  ListNode* getIntersectionNode(ListNode* headA,
                                ListNode* headB) {
    ListNode *p1 = headA, *p2 = headB;
    while (p1 != nullptr && p2 != nullptr) {
      p1 = p1->next;
      p2 = p2->next;
    }
    if (p1 != nullptr) {
      ListNode* temp = headA;
      while (p1 != nullptr) {
        temp = temp->next;
        p1 = p1->next;
      }
      p1 = temp;
      p2 = headB;
    } else if (p2 != nullptr) {
      ListNode* temp = headB;
      while (p2 != nullptr) {
        temp = temp->next;
        p2 = p2->next;
      }
      p2 = temp;
      p1 = headA;
    } else {
      p1 = headA;
      p2 = headB;
    }
    while (p1 != p2) {
      p1 = p1->next;
      p2 = p2->next;
    }
    return p1;
  }
};
