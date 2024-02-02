#include <cstdio>


int main (int argc, char *argv[]) {
  int n;
  scanf("%d", &n);
  double res = 0, temp;
  for(int i = 0; i<n; i++){
    scanf("%lf", &temp);
    res += temp * (i+1) * (n-i);
  }
  printf("%.2f", res);
  return 0;
}
