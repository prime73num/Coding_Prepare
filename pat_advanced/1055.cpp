#include <algorithm>
#include <cstdio>
#include <cstring>


struct person{
  char name[9];
  int age;
  int worth;
}plist[100000], valid[100000];

bool cmp_by_age(person left, person right){
  return left.age < right.age;
}
bool cmp_by_worth(person left, person right){
  if(left.worth != right.worth)
    return left.worth > right.worth;
  if(left.age != right.age)
    return left.age < right.age;
  return strcmp(left.name, right.name) < 0;
}
int agenum[201];

int main (int argc, char *argv[]) {
  int n, query;
  scanf("%d %d", &n, &query);
  for(int i = 0; i<n; i++){
    scanf("%s %d %d", plist[i].name, &plist[i].age, &plist[i].worth);
  }
  std::sort(plist, plist+n, cmp_by_worth);
  int idx = 0;
  for(int i = 0; i<n; i++){
    int age = plist[i].age;
    if(agenum[age] < 100){
      agenum[age]++;
      valid[idx] = plist[i];
      idx++;
    }
  }
  for(int i = 0; i<query; i++){
    int m, min, max;
    scanf("%d %d %d", &m, &min, &max);
    printf("Case #%d:\n", i+1);
    int count = 0;
    for(int i = 0; i<idx; i++){
      if(valid[i].age <= max && valid[i].age >= min){
        printf("%s %d %d\n", valid[i].name, valid[i].age, valid[i].worth);
        count++;
      }
      if(count==m)
        break;
    }
    if(count==0)
      printf("None\n");
  }
  return 0;
}
