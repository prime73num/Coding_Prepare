#include <cstdio>

int main(int argc, char *argv[]) {
  int sum = 0;
  char c = getchar();
  char change[10][5] = {
    "ling",
    "yi",
    "er",
    "san",
    "si",
    "wu",
    "liu",
    "qi",
    "ba",
    "jiu"
  };
  while (c != '\n') {
    sum += c - '0';
    c = getchar();
  }
  int tens = 1;
  while (tens <= sum) 
    tens *= 10;
  tens /= 10;
  while (tens != 1) {
    int idx = sum / tens;
    sum = sum % tens;
    tens /= 10;
    printf("%s ", change[idx]);
  }
  printf("%s", change[sum/tens]);
  return 0;
}
