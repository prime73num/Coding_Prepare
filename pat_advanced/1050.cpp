#include <cstdio>
#include <cstring>
#include <iostream>

bool hashmp[128];

int main (int argc, char *argv[]) {
  char s1[10003];
  char s2[10003];
  for(int i = 0; i<128; i++)
    hashmp[i] = false;
  std::cin.getline(s1, 10003);
  std::cin.getline(s2, 10003);
  int len = strlen(s2);
  for(int i = 0; i<len; i++){
    hashmp[s2[i]] = true;
  }
  len = strlen(s1);
  for(int i = 0; i<len; i++){
    char c = s1[i];
    if(!hashmp[c])
      putchar(c);
  }
  return 0;
}
