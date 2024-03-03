#include "stdc++.h"
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> findAnagrams(string s, string p) {
    vector<int> ans;
    unordered_map<char, int> p_count;
    int count_zero = 0;
    for (char c : p) {
      if (!p_count.count(c)) {
        p_count[c] = 0;
        count_zero++;
      }
      p_count[c]++;
    }
    int len = s.size();
    if (len < p.size())
      return ans;
    for (int i = 0; i < p.size(); i++) {
      char c = s[i];
      if (p_count.count(c)) {
        p_count[c]--;
        if (p_count[c] == 0)
          count_zero--;
      }
    }
    for (int i = 0; i < len - p.size() + 1; i++) {
      if (count_zero == 0)
        ans.push_back(i);
      if (p_count.count(s[i])) {
        if (p_count[s[i]] == 0)
          count_zero++;
        p_count[s[i]]++;
      }
      char c = s[i + p.size()];
      if (p_count.count(c)) {
        p_count[c]--;
        if (p_count[c] == 0)
          count_zero--;
      }
    }
    return ans;
  }
};
