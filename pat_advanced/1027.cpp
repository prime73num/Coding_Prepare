#include <cstdio>

char mp[] = "0123456789ABC";

int main(int argc, char *argv[]) {
  int colors[3];
  scanf("%d %d %d", &colors[0], &colors[1], &colors[2]);
  char res[8];
  res[0] = '#';
  for (int i = 0; i < 3; i++) {
    res[(i + 1) * 2] = mp[colors[i] % 13];
    res[(i + 1) * 2 - 1] = mp[colors[i] / 13];
  }
  res[7] = '\0';
  printf("%s\n", res);

  return 0;
}
