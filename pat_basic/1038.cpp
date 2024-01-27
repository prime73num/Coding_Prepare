#include <cstdio>

int grade[101] = {0};
int main (int argc, char *argv[]) {
  int n;
  scanf("%d", &n);
  for(int i = 0; i<n; i++){
    int temp;
    scanf("%d", &temp);
    grade[temp]++;
  }
  int k;
  scanf("%d", &k);
  for(int i = 0; i<k; i++){
    int temp;
    scanf("%d", &temp);
    if(i==k-1){
      printf("%d", grade[temp]);
    } else {
      printf("%d ", grade[temp]);
    }
  }
  return 0;
}
