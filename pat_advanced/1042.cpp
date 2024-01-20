#include <cstdio>
#include <stdio.h>

int main (int argc, char *argv[]) {
  int n;
  scanf("%d", &n);

  char mp[] = {'S', 'H', 'C', 'D', 'J'};
  int N = 54;
  int start[N];
  int end[N];
  int next[N];
  for(int i = 0; i<N; i++){
    start[i] = i;
  }
  for(int i = 0; i<N; i++){
    scanf("%d", &next[i]);
  }
  for(int i = 0; i<n; i++){
    for(int j = 0; j<N; j++){
      end[next[j]-1] = start[j];
    }
    for(int j = 0; j<N; j++){
      start[j] = end[j];
    }
  }

  for(int i = 0; i<N; i++){
    char c = mp[start[i] / 13];
    if(i!=N-1){
      printf("%c%d ", c, start[i]%13 + 1);
    } else {
      printf("%c%d\n", c, start[i]%13 + 1);
    }
  }


  return 0;
}
