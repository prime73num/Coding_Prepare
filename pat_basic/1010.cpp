#include <cstdio>
#include <stdio.h>

int main (int argc, char *argv[]) {
  int a, b;
  bool first = true;
  while (scanf("%d%d", &a, &b) != EOF) {
    if(b==0) continue;
    if(first){
      printf("%d %d", a*b, b-1);
      first = false;
    } else {
      printf(" %d %d", a*b, b-1);
    }
  }
  if(first){
    printf("0 0");
  }
  return 0;
}
