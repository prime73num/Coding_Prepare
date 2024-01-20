#include <limits.h>
#include <stdio.h>

int main (int argc, char *argv[]) {
  int n;
  scanf("%d", &n);

  int a=0, b=0, c=0, d=0, e=INT_MIN;
  int count[] = {0, 0, 0, 0, 0};
  int signal = 1;
  for (int i = 0; i<n; i++) {
    int temp;
    scanf("%d", &temp);
    int mod = temp % 5;
    if(mod == 0){
      if(temp % 2 == 0){
        a += temp;
        count[mod]++;
      }
    } else if(mod == 1){
      count[mod]++;
      b += temp * signal;
      signal *= -1;
    } else if(mod == 2){
      count[mod]++;
      c++;
    } else if(mod == 3){
      count[mod]++;
      d += temp;
    } else {
      count[mod]++;
      if(temp > e){
        e = temp;
      }
    }
  }
    float f = (float)d/count[3];
    if(count[0] == 0) printf("N ");
    else printf("%d ", a);

    if(count[1] == 0) printf("N ");
    else printf("%d ", b);

    if(count[2] == 0) printf("N ");
    else printf("%d ", c);

    if(count[3] == 0) printf("N ");
    else printf("%.1f ", f);

    if(count[4] == 0) printf("N");
    else printf("%d", e);
  return 0;
}
