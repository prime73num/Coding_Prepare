#include <algorithm>
#include <cstdio>
#include <vector>

const int MAXN = 26*26*26*10 + 1;
std::vector<int> stu_to_class[MAXN];
int hash_name(char name[]){
  int res = 0;
  for(int i = 0; i<3; i++){
    res = res * 26 + name[i] - 'A';
  }
  res = res * 10 + name[3] - '0';
  return res;
}
char stu[10];

int main (int argc, char *argv[]) {
  int query, course_num;
  scanf("%d %d", &query, &course_num);
  for(int i = 0; i<course_num; i++){
    int idx, num;
    scanf("%d %d", &idx, &num);
    for(int j = 0; j<num; j++){
      scanf("%s", stu);
      stu_to_class[hash_name(stu)].push_back(idx);
    }
  }
  for(int i = 0; i<query; i++){
    scanf("%s", stu);
    int idx = hash_name(stu);
    std::vector<int> &list = stu_to_class[idx];
    std::sort(list.begin(), list.end());
    printf("%s %zu", stu, list.size());
    for(int i = 0; i<list.size(); i++){
      printf(" %d", list[i]);
    }
    printf("\n");
  }
  return 0;
}

