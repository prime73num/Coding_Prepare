#include <cstdio>

int main(int argc, char *argv[]) {
  int n, base;
  scanf("%d %d", &n, &base);
  int digital[31];
  int count = 0;
  do {
    digital[count++] = n % base;
    n /= base;
  } while (n != 0);
  bool isp = true;
  for(int i = 0; i*2 < count-1; i++){
    if(digital[i] != digital[count-1 -i]){
      isp = false;
      break;
    }
  }
  if(isp){
    printf("Yes\n");
  } else {
    printf("No\n");
  }
  for(int i = count-1; i>0;i--){
    printf("%d ", digital[i]);
  }
  printf("%d\n", digital[0]);
  return 0;
}
