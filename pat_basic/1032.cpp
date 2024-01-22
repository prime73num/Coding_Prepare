#include <cstdio>


const int MAXN = 100000;

int sum[MAXN + 1];

int main (int argc, char *argv[]) {
  int n;
  scanf("%d", &n);
  for(int i = 0; i<n; i++){
    int idx, score;
    scanf("%d %d", &idx, &score);
    sum[idx] += score;
  }
  int max_idx = 0;
  sum[max_idx] = -1;
  for(int i = 1; i<=n; i++){
    if(sum[i] >= sum[max_idx]){
      max_idx = i;
    }
  }
  printf("%d %d", max_idx, sum[max_idx]);
  return 0;
}
