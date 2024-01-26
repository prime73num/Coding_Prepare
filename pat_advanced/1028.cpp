#include <algorithm>
#include <cstdio>
#include <cstring>

struct stu {
  int id;
  char name[9];
  int score;
} slist[100000];
int row;

bool cmp(stu left, stu right) {
  if (row == 1) {
    return left.id < right.id;
  }
  if (row == 2) {
    int d = strcmp(left.name, right.name);
    if (d != 0)
      return d < 0;
    return left.id < right.id;
  }
  if (row == 3) {
    if (left.score != right.score)
      return left.score < right.score;
    return left.id < right.id;
  }
  return true;
}

int main(int argc, char *argv[]) {
  int n, c;
  scanf("%d %d", &n, &c);
  row = c;
  for(int i = 0; i<n; i++){
    scanf("%d %s %d", &slist[i].id, slist[i].name, &slist[i].score);
  }
  std::sort(slist, slist+n, cmp);
  for(int i = 0; i<n; i++){
    printf("%06d %s %d\n", slist[i].id, slist[i].name, slist[i].score);
  }
}
