#include "stdc++.h"

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
   bool isPalindrome(ListNode* head) {
     ListNode *slow, *fast, *prev, s, *p2;
     s.next = head;
     slow = &s;
     fast = &s;
     prev = nullptr;
     while (true) {
       fast = fast->next;
       p2 = slow->next;
       if(fast==nullptr)
         break;
       fast = fast->next;
       p2 = p2->next;
       if(fast==nullptr)
         break;
       slow = slow->next;

       s.next = slow->next;
       slow->next = prev;
       prev = slow;
       slow = &s;
     }
     while (prev != nullptr) {
       if(prev->val != p2->val)
         return false;
       prev = prev->next;
       p2 = p2->next;
     }
     return true;
   }
};
