#include <cstdio>

int main (int argc, char *argv[]) {
  int target;
  scanf("%d", &target);
  int count_one = 1;
  int mod = 1;
  int res = 0;
  while (true) {
    int right = target % mod;
    int mid = (target/mod) % 10;
    int left = (target/mod) / 10;
    if(mid > count_one){
      res += (left+1)*mod;
    } else if(mid == count_one){
      res += left * mod + right + 1;
    } else {
      res += left*mod;
    }
    if(left==0) break;
    mod *= 10;
  }
  printf("%d", res);
  return 0;
}
