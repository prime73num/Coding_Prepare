#include <cstdio>

int count[10];
int main (int argc, char *argv[]) {
  char c;
  c = getchar();
  while (c!='\n') {
    count[c-'0']++;
    c=getchar();
  }
  for(int i = 0; i<10; i++){
    if(count[i]==0) continue;
    printf("%d:%d\n", i, count[i]);
  }
  return 0;
}
