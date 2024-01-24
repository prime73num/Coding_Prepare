#include <cstdio>

int main (int argc, char *argv[]) {
  int n;
  char c;
  scanf("%d %c", &n, &c);
  int k = 1;
  for(; 2*k*k-1<=n; k++) {}
  k--;
  int rows = 2*k - 1;
  for(int i = 0; i<rows; i++){
    for(int j = 0; j<rows; j++){
      int s = i, e = rows-1-i;
      if(s > e){
        int temp = s;
        s = e; e = temp;
      }
      if( j>=s && j<=e){
        printf("%c", c);
      } else if(j < s){
        printf(" ");
      }
    }
    printf("\n");
  }
  printf("%d\n", n-2*k*k+1);
  return 0;
}
