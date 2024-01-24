#include <cstdio>

int res[31] = {0};
int main (int argc, char *argv[]) {
  unsigned int a, b, d;
  scanf("%d %d %d", &a, &b, &d);
  unsigned int sum = a+b;
  int count = 0;
  while (sum != 0) {
    res[count++] = sum % d;
    sum/=d;
  }
  if(count != 0){
    count--;
  }
  for(int i = count; i>=0; i--){
    printf("%d", res[i]);
  }
  printf("\n");
  return 0;
}
