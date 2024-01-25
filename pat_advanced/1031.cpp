#include <cstdio>
#include <cstring>
#include <iostream>

int main (int argc, char *argv[]) {
  char str[100];
  std::cin.getline(str, 100);
  int N = strlen(str);
  int n1 = (N+2)/3;
  int n3 = n1;
  int n2 = N+2 - n1 - n3;
  for(int i = 0; i<n1-1; i++){
    printf("%c", str[i]);
    for(int j = 0; j<n2-2; j++)
      printf(" ");
    printf("%c\n", str[N-1-i]);
  }
  for(int i = 0; i<n2; i++){
    printf("%c", str[i+n1-1]);
  }
  printf("\n");
  return 0;
}
