#include "stdc++.h"


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
   ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
     ListNode head, *tail;
     tail = &head;
     int carry = 0;
     while (l1 != nullptr || l2 != nullptr) {
       ListNode *node = new ListNode();
       int sum = 0;
       if(l1 != nullptr){
         sum += l1->val;
         l1 = l1->next;
       }
       if(l2 != nullptr){
         sum += l2->val;
         l2 = l2->next;
       }
       sum += carry;
       node->val = sum % 10;
       carry = sum/10;
       tail->next = node;
       tail = tail->next;
     }
     if(carry != 0){
       ListNode *node = new ListNode();
       node->val = carry;
       tail->next = node;
       tail = tail->next;
     }
     return head.next;
   }
};
