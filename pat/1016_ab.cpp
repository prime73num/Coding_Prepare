#include <cstdio>
#include <stdio.h>

int main (int argc, char *argv[]) {
  int a, da, b, db;
  scanf("%d%d%d%d", &a, &da, &b, &db);
  int temp_a = 0;
  while (a != 0) {
    if(a % 10 == da){
      temp_a = temp_a*10 + da;
    }
    a /= 10;
  }
  int temp_b = 0;
  while (b != 0) {
    if(b % 10 == db){
      temp_b = temp_b*10 + db;
    }
    b /= 10;
  }
  printf("%d", temp_a+temp_b);
  return 0;
}
