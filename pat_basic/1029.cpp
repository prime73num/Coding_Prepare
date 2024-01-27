#include <cstdio>
#include <cstring>
#include <iostream>

int main (int argc, char *argv[]) {
  bool hashmp[128];
  for(int i = 0; i<128; i++){
    hashmp[i] = false;
  }
  char correct[81];
  char actual[81];
  std::cin.getline(correct, 81);
  std::cin.getline(actual, 81);
  int a = strlen(correct);
  int b = strlen(actual);
  int n = 0, m = 0;
  while (n<a) {
    if(correct[n] == actual[m]){
      n++;
      m++;
      continue;
    }
    char temp = correct[n];
    if(temp >= 'a' && temp <= 'z') temp -= 32;
    if(!hashmp[temp]){
      printf("%c", temp);
      hashmp[temp] = true;
    }
    n++;
  }
  printf("\n");
  return 0;
}
