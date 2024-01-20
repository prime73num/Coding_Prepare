#include <stdio.h>

int main (int argc, char *argv[]) {
  int times;
  scanf("%d", &times);
  int t = times;
  while (t--) {
    long long a, b, c;
    scanf("%lld%lld%lld", &a, &b, &c);
    if(a + b > c){
      printf("Case #%d: true\n", times - t);
    } else {
      printf("Case #%d: false\n", times - t);
    }
  }
  return 0;
}
