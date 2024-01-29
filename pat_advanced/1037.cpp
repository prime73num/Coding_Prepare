#include <algorithm>
#include <cstdio>


int coupons[100000];
int product[100000];

int main (int argc, char *argv[]) {
  int nc, np;
  scanf("%d", &nc);
  for(int i = 0; i<nc; i++){
    scanf("%d", &coupons[i]);
  }
  scanf("%d", &np);
  for(int i = 0; i<np; i++){
    scanf("%d", &product[i]);
  }
  std::sort(coupons, coupons+nc);
  std::sort(product, product+np);
  int res = 0;
  int a = 0, b = 0;
  while (a < nc && b < np && coupons[a] < 0 && product[b] < 0) {
    res += coupons[a] * product[b];
    a++;
    b++;
  }
  a = nc - 1;
  b = np - 1;
  while (a >= 0 && b >= 0 && coupons[a] > 0 && product[b] > 0) {
    res += coupons[a] * product[b];
    a--;
    b--;
  }
  printf("%d", res);
  return 0;
}
