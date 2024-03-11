#include "stdc++.h"
#include <vector>
using namespace std;

class Solution {
public:
  char mp[256];
  bool isValid(string s) {
    mp[')'] = '(';
    mp[']'] = '[';
    mp['}'] = '{';
    vector<char> queue;
    for(int i = 0; i<s.size(); i++){
      char c = s[i];
      if(c == '(' || c == '{' || c == '[')
        queue.push_back(c);
      else {
        if(queue.empty())
          return false;
        if(queue.back() != mp[c])
          return false;
        queue.pop_back();
      }
    }
    return queue.empty();
  }
};
