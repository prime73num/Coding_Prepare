#include "stdc++.h"
using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
   bool hasCycle(ListNode *head) {
     ListNode *slow, *fast;
     ListNode s = ListNode(0);
     s.next = head;
     slow = &s, fast = &s;
     while (true) {
       slow = slow->next;
       fast = fast->next;
       if(fast == nullptr)
         return false;
       fast = fast->next;
       if(fast == nullptr)
         return false;
       if(slow == fast)
         break;
     }
     return true;
   }
};
