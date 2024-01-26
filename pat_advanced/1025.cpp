#include <algorithm>
#include <cstdio>
#include <cstring>

struct stu {
  char id[14];
  int score;
  int location;
  int rank;
  int localrank;
} stulist[30000];

bool cmp1(stu left, stu right) {
  if (left.score != right.score)
    return left.score > right.score;
  return strcmp(left.id, right.id) < 0;
}
bool cmp2(stu left, stu right) {
  if (left.location != right.location)
    return left.location < right.location;
  if (left.score != right.score)
    return left.score > right.score;
  return strcmp(left.id, right.id) < 0;
}

int main(int argc, char *argv[]) {
  int n;
  scanf("%d", &n);
  int count = 0;
  for (int i = 0; i < n; i++) {
    int k;
    scanf("%d", &k);
    for (int j = 0; j < k; j++) {
      scanf("%s %d", stulist[count].id, &stulist[count].score);
      stulist[count].location = i + 1;
      count++;
    }
  }
  std::sort(stulist, stulist + count, cmp2);
  int pre_location = 0;
  int begin = 0;
  for (int i = 0; i < count; i++) {
    if (stulist[i].location != pre_location) {
      begin = i;
      pre_location = stulist[i].location;
      stulist[i].localrank = 1;
      continue;
    }
    if (stulist[i].score != stulist[i - 1].score)
      stulist[i].localrank = i + 1 - begin;
    else
      stulist[i].localrank = stulist[i - 1].localrank;
  }

  std::sort(stulist, stulist + count, cmp1);
  stulist[0].rank = 1;
  for (int i = 1; i < count; i++) {
    if (stulist[i].score != stulist[i - 1].score)
      stulist[i].rank = i + 1;
    else
      stulist[i].rank = stulist[i - 1].rank;
  }
  printf("%d\n", count);
  for (int i = 0; i < count; i++) {
    printf("%s %d %d %d\n", stulist[i].id, stulist[i].rank, stulist[i].location,
           stulist[i].localrank);
  }
  return 0;
}
