#include "stdc++.h"
#include <vector>
using namespace std;



class Solution {
public:
    string decodeString(string s) {
      string ans;
      vector<int> times;
      vector<int> idx;
      int num = 0;
      for(int i = 0; i<s.size(); i++){
        char c = s[i];
        if(c == '['){
          idx.push_back(ans.size());
          times.push_back(num);
          num = 0;
        } else if(c == ']'){
          int l = idx.back();
          int t = times.back() - 1;
          idx.pop_back();
          times.pop_back();

          string temp = ans.substr(l, ans.size() - l);
          while (t--)
            ans += temp;
        } else if(c >= '0' && c <= '9'){
          num = num*10 + c - '0';
        } else {
          ans.push_back(c);
        }
      }
      return ans;
    }
};
