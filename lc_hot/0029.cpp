#include "stdc++.h"
#include <vector>

using namespace std;


class Node {
public:
  int val;
  Node* next;
  Node* random;

  Node(int _val) {
    val = _val;
    next = nullptr;
    random = nullptr;
  }
};

class Solution {
public:
  Node* copyRandomList(Node* head) {
    Node start(0);
    Node* p1 = head;
    Node* p2 = &start;
    vector<Node*> node_pos;
    while (p1!=nullptr) {
      Node *t = new Node(p1->val);
      node_pos.push_back(t);
      p2->next = t;
      p2 = t;
      p1->val = node_pos.size()-1;
      p1 = p1->next;
    }
    p1 = head;
    p2 = start.next;
    while (p1 != nullptr) {
      if(p1->random==nullptr)
        p2->random = nullptr;
      else {
        p2->random = node_pos[p1->random->val];
      }
      p1 = p1->next;
      p2 = p2->next;
    }
    return start.next;
  }
};
