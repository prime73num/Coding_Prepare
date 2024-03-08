#include "stdc++.h"
#include <queue>
using namespace std;

struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
  struct warp {
    int val;
    ListNode* node;
    bool operator<(const warp& rhs) const { return val > rhs.val; }
  };
  ListNode* mergeKLists(vector<ListNode*>& lists) {
    priority_queue<warp> queue;
    for (ListNode* node : lists) {
      if(node == nullptr)
        continue;
      queue.push(warp{.val = node->val, .node = node});
    }
    ListNode s;
    ListNode* tail = &s;
    while (!queue.empty()) {
      ListNode* temp = queue.top().node;
      tail->next = temp;
      tail = temp;
      queue.pop();
      if (temp->next != nullptr) {
        temp = temp->next;
        queue.push(warp{.val = temp->val, .node = temp});
      }
    }
    return s.next;
  }
};
