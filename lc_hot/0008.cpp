#include "stdc++.h"
#include <algorithm>

using namespace std;

class Solution {
public:
  int lengthOfLongestSubstring(string s) {
    int ans = 0;
    int start = 0, size = s.size(), end = 0;
    unordered_map<char, int> pos;
    while (start < size) {
      bool find = false;
      while (end < size) {
        char t = s[end];
        if (pos.find(t) == pos.end() || pos[t] < start) {
          pos[s[end]] = end;
          end++;
          continue;
        }
        find = true;
        break;
      }
      if (find) {
        ans = max(ans, end - start);
        start = pos[s[end]] + 1;
      } else {
        ans = max(ans, end - start);
        break;
      }
    }
    return ans;
  }
};
