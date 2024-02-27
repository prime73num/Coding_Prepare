#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>

const int MAXN = 2510;
const int MAXNS = 40010;
std::vector<int> classes[MAXN];
char name[MAXNS][5];

bool cmp(int a, int b){
  return strcmp(name[a], name[b])<0;
}

int main (int argc, char *argv[]) {
  int stu_num, course_num;
  scanf("%d %d", &stu_num, &course_num);
  for(int i = 0; i<stu_num; i++){
    int n;
    scanf("%s %d", name[i], &n);
    for(int j = 0; j<n; j++){
      int temp;
      scanf("%d", &temp);
      classes[temp].push_back(i);
    }
  }
  for(int i = 1; i<=course_num; i++){
    std::vector<int> &list = classes[i];
    std::sort(list.begin(), list.end(), cmp);
    printf("%d %zu\n", i, list.size());
    for(int j = 0; j<list.size(); j++){
      printf("%s\n", name[list[j]]);
    }
  }
  return 0;
}
