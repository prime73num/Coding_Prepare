#include <cstdio>


int main (int argc, char *argv[]) {
  bool hashmp[256];
  for(int i = 0; i<256; i++)
    hashmp[i] = true;
  char c;
  c = getchar();
  while (c != '\n') {
    if(c=='+'){
      for(char c = 'A'; c <= 'Z'; c++){
        hashmp[c] = false;
      }
    } else if(c >= 'A' && c <= 'Z'){
      hashmp[c] = false;
      c += 32;
      hashmp[c] = false;
    } else {
      hashmp[c] = false;
    }
    c = getchar();
  }
  c = getchar();
  while (c != '\n') {
    if(hashmp[c])
      putchar(c);
    c = getchar();
  }
  printf("\n");
  return 0;
}
