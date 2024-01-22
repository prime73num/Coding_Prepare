#include <cstdio>

struct person{
  char name[6];
  int year, month, day;
};

bool lesseq(person left, person right){
  if(left.year != right.year)
    return left.year < right.year;
  if(left.month != right.month)
    return left.month < right.month;
  return left.day < right.day;
}

int main (int argc, char *argv[]) {
  int n;
  scanf("%d", &n);
  int count = 0;
  person oldest, youngest;
  oldest.year = 1814;
  oldest.month = 9;
  oldest.day = 6;
  youngest.year = 2014;
  youngest.month = 9;
  youngest.day = 6;
  person max = youngest, min = oldest;
  for(int i = 0; i<n; i++){
    person temp;
    scanf("%s %d/%d/%d", temp.name, &temp.year, &temp.month, &temp.day);
    if(lesseq(temp, oldest) || lesseq(youngest, temp)) continue;
    count++;
    if(lesseq(temp, max))
      max = temp;
    if(lesseq(min, temp))
      min = temp;
  }
  if(count == 0)
    printf("%d", count);
  else
    printf("%d %s %s", count, max.name, min.name);
  return 0;
}
