#include <cstdio>
#include <cstring>
#include <iostream>


int hashmp[128];
char sentence[1003];

int main (int argc, char *argv[]) {
  std::cin.getline(sentence, 1003);
  int len = strlen(sentence);
  for(int i = 0; i<len; i++){
    char c = sentence[i];
    if(c >= 'A' && c <= 'Z')
      c += 32;
    hashmp[c]++;
  }
  char idx = 'a';
  for(char c = 'b'; c <= 'z'; c++){
    if(hashmp[c] > hashmp[idx])
      idx = c;
  }
  printf("%c %d", idx, hashmp[idx]);
  return 0;
}
