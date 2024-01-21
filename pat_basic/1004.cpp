#include <cstdio>

struct Stu {
  char name[11];
  char id[11];
  int score;
}min, max;


int main (int argc, char *argv[]) {
  int n;
  min.score = 110;
  max.score = -2;
  scanf("%d", &n);
  for(int i = 0; i<n; i++){
    struct Stu temp;
    scanf("%s%s%d", temp.name, temp.id, &temp.score);
    if(temp.score > max.score){
      max = temp;
    }
    if(temp.score < min.score){
      min = temp;
    }
  }
  printf("%s %s\n", max.name, max.id);
  printf("%s %s\n", min.name, min.id);
  return 0;
}
