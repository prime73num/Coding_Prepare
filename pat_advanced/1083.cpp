#include <algorithm>
#include <cstdio>

struct stu{
  char name[11];
  char id[11];
  int grade;
}slist[50];

bool cmp(stu left, stu right){
  return left.grade > right.grade;
}

int main (int argc, char *argv[]) {
  int n;
  scanf("%d", &n);
  for(int i = 0; i<n; i++){
    scanf("%s %s %d", slist[i].name, slist[i].id, &slist[i].grade);
  }
  int min, max;
  scanf("%d %d", &min, &max);

  int idx = 0;
  for(int i = 0; i<n; i++){
    int temp = slist[i].grade;
    if(temp >= min && temp <= max)
      slist[idx++] = slist[i];
  }
  std::sort(slist, slist+idx, cmp);
  if(idx == 0){
    printf("NONE\n");
  } else {
    for(int i = 0; i<idx; i++){
      printf("%s %s\n", slist[i].name, slist[i].id);
    }
  }
  return 0;
}
