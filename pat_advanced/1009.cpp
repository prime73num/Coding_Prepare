#include <cstdio>


const int MAXN = 1001;
float p[MAXN];
float sum[MAXN*2];

int main (int argc, char *argv[]) {
  int k;
  int exp;
  float coff;
  scanf("%d", &k);
  for(int i = 0; i<k; i++){
    scanf("%d%f", &exp, &coff);
    p[exp] = coff;
  }
  scanf("%d", &k);
  for(int i = 0; i<k; i++){
    scanf("%d%f", &exp, &coff);
    for(int i = 0; i<MAXN; i++){
      sum[exp+i] += coff * p[i];
    }
  }
  int count = 0;
  for(int i = MAXN*2; i>=0; i--){
    if(sum[i] != 0)
      count++;
  }
  printf("%d", count);
  for(int i = MAXN*2; i>=0; i--){
    if(sum[i]==0)
      continue;
    printf(" %d %.1f", i, sum[i]);
  }
  return 0;
}
