#include "stdc++.h"


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
   ListNode *detectCycle(ListNode *head) {
     ListNode *slow, *fast, s(0);
     s.next = head;
     slow = &s;
     fast = &s;
     while (true) {
       fast = fast->next;
       if(fast == nullptr)
         return nullptr;
       fast = fast->next;
       if(fast == nullptr)
         return nullptr;
       slow = slow->next;
       if(slow == fast)
         break;
     }
     slow = &s;
     while (true) {
       slow = slow->next;
       fast = fast->next;
       if(slow == fast)
         break;
     }
     return slow;
   }
};
