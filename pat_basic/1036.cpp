#include <cstdio>

int main (int argc, char *argv[]) {
  int a;
  char c;
  scanf("%d %c", &a, &c);
  int colunms = a;
  int rows = a%2 == 0 ? a/2:(a+1)/2;
  if(rows == 1){
    printf("%c", c);
    return 0;
  }
  for(int i = 0; i<colunms; i++){
    printf("%c", c);
  }
  printf("\n");
  for(int i = 0; i<rows-2; i++){
    printf("%c", c);
    for(int i = 0; i<colunms-2; i++){
      printf(" ");
    }
    printf("%c\n", c);
  }
  for(int i = 0; i<colunms; i++){
    printf("%c", c);
  }
  printf("\n");
  return 0;
}
