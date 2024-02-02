#include <cstdio>
#include <cstring>

char str[104];

bool getres() {
  int a = 0, b = 0, c = 0;
  int len = strlen(str);
  int p = 0;
  while (p<len) {
    if(str[p] == 'A')
      a++;
    else if(str[p] == 'P'){
      p++;
      break;
    }
    else
     return false;;
    p++;
  }
  if(p==len)
    return false;
  while (p<len) {
    if(str[p] == 'A')
      b++;
    else if(str[p] == 'T'){
      p++;
      break;
    }
    else
      return false;;
    p++;
  }
  while (p<len) {
    if(str[p] == 'A')
      c++;
    else
      return false;;
    p++;
  }
  if(b<1 || c != a*b)
    return false;
  return true;
}

int main(int argc, char *argv[]) {
  int n;
  scanf("%d\n", &n);
  for (int i = 0; i < n; i++) {
    scanf("%s", str);
    if(getres()){
      printf("YES\n");
    } else {
      printf("NO\n");
    }
  }
  return 0;
}
