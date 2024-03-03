#include "stdc++.h"
#include <unordered_map>

using namespace std;

class Solution {
public:
  vector<vector<string>> groupAnagrams(vector<string> &strs) {
    vector<vector<string>> res;
    unordered_map<string, vector<string>> mp;
    int len = strs.size();
    for (int i = 0; i < len; i++) {
      string temp = strs[i];
      sort(temp.begin(), temp.end());
      mp[temp].push_back(strs[i]);
    }
    for (unordered_map<string, vector<string>>::iterator it = mp.begin();
         it != mp.end(); it++) {
      res.push_back(it->second);
    }
    return res;
  }
};

int main(int argc, char *argv[]) {
  Solution sol;
  return 0;
}
