#include <algorithm>
#include <cstdio>
#include <iostream>
#include <string>

std::string str[10003];

bool cmp(std::string a, std::string b){
  return a+b < b+a;
}

int main (int argc, char *argv[]) {
  int n;
  scanf("%d", &n);
  for(int i = 0; i<n; i++){
    std::cin>>str[i];
  }
  std::sort(str, str+n, cmp);
  std::string ans = "";
  for(int i = 0; i<n; i++){
    ans += str[i];
  }
  while (ans.size() != 0 && ans[0]=='0') {
    ans.erase(ans.begin());
  }
  if(ans.size() == 0){
    printf("0");
  } else {
    std::cout<<ans;
  }
  return 0;
}
