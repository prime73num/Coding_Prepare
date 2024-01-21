#include <cstdio>

const int MAXN = 1001;
float sum[MAXN];
int main(int argc, char *argv[]) {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    int exp;
    float coff;
    scanf("%d%f", &exp, &coff);
    sum[exp] = coff;
  }
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    int exp;
    float coff;
    scanf("%d%f", &exp, &coff);
    sum[exp] += coff;
  }
  int count = 0;
  for (int i = MAXN - 1; i >= 0; i--) {
    if (sum[i] != 0) {
      count++;
    }
  }
  printf("%d", count);
  for (int i = MAXN - 1; i >= 0; i--) {
    if (sum[i] == 0)
      continue;
    printf(" %d %.1f", i, sum[i]);
  }
  return 0;
}
