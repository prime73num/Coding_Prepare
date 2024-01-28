#include <cstdio>


int num[10];

int main (int argc, char *argv[]) {
  for(int i = 0; i<10; i++)
    scanf("%d", &num[i]);

  for(int i = 1; i<10; i++){
    if(num[i] != 0){
      num[i]--;
      printf("%d", i);
      break;
    }
  }
  for(int i = 0; i<10; i++){
    if(num[i] != 0){
      for(int j = 0; j<num[i]; j++)
        printf("%d", i);
    }
  }
  return 0;
}
