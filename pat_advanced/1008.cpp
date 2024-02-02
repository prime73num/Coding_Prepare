#include <cstdio>

int main (int argc, char *argv[]) {
  int n;
  scanf("%d", &n);
  int pre = 0;
  int res = 0;
  for(int i = 0; i<n; i++){
    int next;
    scanf("%d", &next);
    if(next > pre){
      res += (next-pre) * 6 + 5;
    } else {
      res += (pre - next) * 4 + 5;
    }
    pre = next;
  }
  printf("%d", res);
  return 0;
}
