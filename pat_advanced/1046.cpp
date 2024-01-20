#include <cstdio>
#include <cstdlib>
#include <stdio.h>
int main(int argc, char *argv[]) {
  int n;
  scanf("%d", &n);
  int *dis = (int *)malloc(sizeof(int) * n+1);
  dis[0] = 0;
  for (int i = 0; i < n; i++) {
    int temp;
    scanf("%d", &temp);
    dis[i+1] = temp + dis[i];
  }
  int sum = dis[n];
  int m;
  scanf("%d", &m);
  for (int i = 0; i < m; i++) {
    int s, e;
    scanf("%d %d", &s, &e);
    if(s > e){
      int temp = e;
      e= s; s = temp;
    }
    int count = dis[e-1] - dis[s-1];

    if(count * 2 > sum){
      count = sum - count;
    }
    printf("%d\n", count);
  }
  return 0;
}
