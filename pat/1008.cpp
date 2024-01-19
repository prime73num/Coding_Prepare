#include <stdlib.h>
#include <stdio.h>
int main (int argc, char *argv[]) {
  int n, shift;
  scanf("%d%d", &n, &shift);
  shift %= n;
  int* a = (int *)malloc(sizeof(int) * n);
  for (int i = 0; i<n; i++) {
    scanf("%d", &a[i]);
  }
  int s = 0, e = n - shift - 1;
  while (s < e) {
    int temp = a[s];
    a[s] = a[e];
    a[e] = temp;
    s++;
    e--;
  }
  s = n-shift, e = n - 1;
  while (s < e) {
    int temp = a[s];
    a[s] = a[e];
    a[e] = temp;
    s++;
    e--;
  }
  s = 0, e = n - 1;
  while (s < e) {
    int temp = a[s];
    a[s] = a[e];
    a[e] = temp;
    s++;
    e--;
  }
  for(int i = 0; i<n; i++){
    if(i==n-1){
      printf("%d", a[i]);
    } else {
      printf("%d ", a[i]);
    }
  }
  free(a);
  return 0;
}
