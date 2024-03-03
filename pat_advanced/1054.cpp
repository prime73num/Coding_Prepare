#include <cstdio>

int main(int argc, char *argv[]) {
  int m, n;
  scanf("%d %d", &m, &n);
  int total = m * n;
  int most_color = 0;
  int count = 1;
  for (int i = 0; i < total; i++) {
    int color;
    scanf("%d", &color);

    if (count == 0) {
      most_color = color;
      count = 1;
    } else if (color == most_color) {
      count++;
    } else {
      count--;
    }
  }
  printf("%d\n", most_color);
  return 0;
}
