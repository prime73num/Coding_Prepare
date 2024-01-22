#include <cstdio>

struct stu{
  char name[11];
  char gender;
  char id[11];
  int grade;
};


int main (int argc, char *argv[]) {
  int n;
  scanf("%d", &n);
  stu highest_f, lowest_m;
  highest_f.grade = -1;
  lowest_m.grade = 101;
  for(int i = 0; i<n; i++){
    stu temp;
    scanf("%s %c %s %d", temp.name, &temp.gender, temp.id, &temp.grade);
    if(temp.gender == 'F' && temp.grade > highest_f.grade){
      highest_f = temp;
    }
    if(temp.gender == 'M' && temp.grade < lowest_m.grade){
      lowest_m = temp;
    }
  }
  if(highest_f.grade == -1){
    printf("Absent\n");
  } else {
    printf("%s %s\n", highest_f.name, highest_f.id);
  }
  if(lowest_m.grade == 101){
    printf("Absent\n");
  } else {
    printf("%s %s\n", lowest_m.name, lowest_m.id);
  }
  if(highest_f.grade == -1 || lowest_m.grade == 101){
    printf("NA\n");
  } else {
    printf("%d\n", highest_f.grade - lowest_m.grade);
  }
  return 0;
}
