#include <stdio.h>

int main (int argc, char *argv[]) {
  int start, end;
  scanf("%d%d", &start, &end);

  int clock = end - start;
  int time = clock / 100;
  if(clock % 100 >= 50){
    time++;
  }
  int sec = time % 60;
  time /= 60;
  int min = time % 60;
  time /= 60;
  int hour = time % 60;

  printf("%02d:%02d:%02d", hour, min, sec);
  return 0;
}
