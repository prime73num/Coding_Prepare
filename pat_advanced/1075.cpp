#include <algorithm>
#include <cstdio>
#include <climits>

struct user {
  int id;
  int problem[6];
  int total;
  int perfect_solve;
  bool remove;
} ulist[10003];

int mark[6];

bool cmp(user left, user right) {
  if (left.total != right.total)
    return left.total > right.total;
  if (left.perfect_solve != right.perfect_solve)
    return left.perfect_solve > right.perfect_solve;
  return left.id < right.id;
}

int main(int argc, char *argv[]) {
  int n, k, m;
  scanf("%d %d %d", &n, &k, &m);
  for (int i = 0; i < k; i++) {
    scanf("%d", &mark[i + 1]);
  }
  for (int i = 1; i <= n; i++) {
    ulist[i].id = i;
    for (int j = 0; j < 6; j++) {
      ulist[i].problem[j] = -2;
    }
  }
  for (int i = 0; i < m; i++) {
    int id, prob, mark;
    scanf("%d %d %d", &id, &prob, &mark);
    int &temp = ulist[id].problem[prob];
    if (temp < mark)
      temp = mark;
  }
  for (int i = 1; i <= n; i++) {
    ulist[i].total = 0;
    ulist[i].perfect_solve = 0;
    ulist[i].remove = true;
    for (int j = 1; j <= k; j++) {
      if (ulist[i].problem[j] >= 0) {
        ulist[i].total += ulist[i].problem[j];
        ulist[i].remove = false;
      }
      if (ulist[i].problem[j] == mark[j]) {
        ulist[i].perfect_solve++;
      }
    }
    if(ulist[i].remove)
      ulist[i].total = INT_MIN;
  }

  std::sort(ulist + 1, ulist + 1 + n, cmp);

  int rank = 1;
  printf("%d %05d %d", rank, ulist[1].id, ulist[1].total);
  for (int i = 1; i <= k; i++) {
    int mark = ulist[1].problem[i];
    if (mark == -2)
      printf(" -");
    else
      printf(" %d", ulist[1].problem[i]);
  }
  printf("\n");
  for (int i = 2; i <= n; i++) {
    if(ulist[i].remove) break;
    if (ulist[i].total != ulist[i - 1].total)
      rank = i;
    printf("%d %05d %d", rank, ulist[i].id, ulist[i].total);
    for (int j = 1; j <= k; j++) {
      int mark = ulist[i].problem[j];
      if (mark == -2)
        printf(" -");
      else if(mark == -1)
        printf(" 0");
      else
        printf(" %d", ulist[i].problem[j]);
    }
    printf("\n");
  }
  return 0;
}
