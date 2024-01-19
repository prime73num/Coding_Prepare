#include <stdio.h>


int main (int argc, char *argv[]) {
  int n;
  scanf("%d", &n);

  int acount = 0, bcount = 0;
  while (n--) {
    int a, pa, b, pb;
    scanf("%d%d%d%d", &a, &pa, &b, &pb);
    int sum = a + b;
    if(pa == sum && pb == sum){
      continue;
    }
    if(pa != sum && pb != sum){
      continue;
    }
    if(pa == sum)
      bcount++;
    if(pb == sum)
      acount++;
  }
  printf("%d %d", acount, bcount);
  return 0;
}
