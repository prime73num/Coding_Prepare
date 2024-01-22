#include <cstdio>

int main (int argc, char *argv[]) {
  float times = 0.65;
  char mp[] = {'W', 'T', 'L'};
  for(int i = 0; i<3; i++){
    float rate[3];
    scanf("%f%f%f", &rate[0], &rate[1], &rate[2]);
    int idx = -1;
    float max = -1;
    for(int j = 0; j<3; j++){
      if(rate[j] > max){
        max = rate[j];
        idx = j;
      }
    }
    times *= max;
    printf("%c ", mp[idx]);
  }
  printf("%.2f", (times-1)*2);
  return 0;
}
