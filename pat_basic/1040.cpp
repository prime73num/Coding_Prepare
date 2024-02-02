#include <cstdio>
#include <cstring>

char str[100005];

int main(int argc, char *argv[]) {
  scanf("%s", str);
  int n = strlen(str);
  int left_p = 0;
  int right_t = 0;
  for (int i = 0; i < n; i++) {
    if (str[i] == 'T')
      right_t++;
  }
  int res = 0;
  for (int i = 0; i < n; i++) {
    if (str[i] == 'A'){
      res += left_p * right_t;
      res %= 1000000007;
    }
    if(str[i] == 'P')
      left_p++;
    if(str[i] == 'T')
      right_t--;
  }
  printf("%d", res);
  return 0;
}
