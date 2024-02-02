#include <algorithm>
#include <cstdio>

char str[10];

bool cmp(char a, char b){
  return a>b;
}

int getvalue() {
  int res = 0;
  for (int i = 0; i<4; i++){
    res = res*10+str[i]-'0';
  }
  return res;
}
void to_array(int num){
  for(int i = 3; i>=0; i--){
    str[i] = (num % 10) + '0';
    num /= 10;
  }
}

int main(int argc, char *argv[]) {
  int temp;
  scanf("%d", &temp);
  to_array(temp);
  while (true) {
    std::sort(str, str+4);
    int a = getvalue();
    std::sort(str, str+4, cmp);
    int b = getvalue();
    int c = b - a;
    to_array(c);
    printf("%04d - %04d = %04d\n", b, a, c);
    if(c==0 || c==6174)
      break;
  }
}
