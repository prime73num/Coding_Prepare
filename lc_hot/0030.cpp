struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
   ListNode* sortList(ListNode* head) {
     ListNode start;
     start.next = head;
     ListNode* p = head;
     int size = 0;
     while (p != nullptr) {
       size++;
       p = p->next;
     }
     for(int i = 0; i<size-1; i++){
       p = &start;
       int times = size - 1 - i;
       while (times--) {
         ListNode* next = p->next->next;
         if(p->next->val > next->val){
           p->next->next = next->next;
           next->next = p->next;
           p->next = next;
         }
         p = p->next;
       }
     }
     return start.next;
   }
};
