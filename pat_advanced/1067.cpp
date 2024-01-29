#include <cstdio>

int idx[100000];

void myswap(int a){
  int temp = idx[0];
  idx[0] = idx[a];
  idx[a] = temp;
}

int main (int argc, char *argv[]) {
  int length;
  scanf("%d", &length);
  for(int j = 0; j<length; j++){
    int temp;
    scanf("%d", &temp);
    idx[temp] = j;
  }
  int res = 0;
  while (idx[0] != 0) {
    int temp = idx[0];
    myswap(temp);
    res++;
  }
  int i = 0;
  while (true) {
    for(; i<length; i++){
      if(idx[i] != i)
        break;
    }
    if(i==length)
      break;
    myswap(i);
    res++;
    while (idx[0] != 0) {
      int temp = idx[0];
      myswap(temp);
      res++;
    }
  }
  printf("%d", res);
  return 0;
}
