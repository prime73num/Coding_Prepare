#include <cstdio>
#include <cstring>
#include <iostream>


int hashmp[128] = {0};

int main (int argc, char *argv[]) {
  char sell[1001];
  char want[1001];
  std::cin.getline(sell, 1001);
  std::cin.getline(want, 1001);
  int sell_len = strlen(sell);
  for(int i = 0; i<sell_len; i++){
    hashmp[sell[i]]++;
  }
  int want_len = strlen(want);
  int count = 0;
  for(int i = 0; i<want_len; i++){
    char c = want[i];
    if(hashmp[c] > 0){
      hashmp[c]--;
      count++;
    }
  }
  if(count==want_len){
    printf("Yes %d", sell_len-count);
  } else {
    printf("No %d", want_len-count);
  }
  return 0;
}
