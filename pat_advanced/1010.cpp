#include <algorithm>
#include <cstdio>
#include <cstring>

char n1[13];
char n2[13];
char temp[13];
int mp[256];
void init() {
  for (char c = '0'; c <= '9'; c++) {
    mp[c] = c - '0';
  }
  for (char c = 'a'; c <= 'z'; c++) {
    mp[c] = c - 'a' + 10;
  }
}

long long to_decimal(char str[], long long radix) {
  long long res = 0;
  int len = strlen(str);
  for (int i = 0; i<len; i++) {
    res = mp[str[i]] + res*radix;
  }
  return res;
}
int max_digital(char* str){
  int res = 0;
  int len = strlen(str);
  for (int i = 0; i<len; i++) {
    if(mp[str[i]] > res)
      res = mp[str[i]];
  }
  return res;
}

int main(int argc, char *argv[]) {
  init();
  int tag, radix;
  scanf("%s %s %d %d", n1, n2, &tag, &radix);

  if (tag == 2) {
    strcpy(temp, n1);
    strcpy(n1, n2);
    strcpy(n2, temp);
  }
  long long sum = to_decimal(n1, radix);
  long long s = max_digital(n2) + 1;
  long long e = std::max(s, sum) + 1;
  long long mid;
  bool found = false;
  while (s <= e) {
    mid = (s+e)/2;
    long long temp = to_decimal(n2, mid);
    if(temp == sum){
      found = true;
      break;
    }
    if(temp < sum) s = mid+1;
    else e = mid-1;
  }
  if(found)
    printf("%lld", mid);
  else
   printf("Impossible");
  return 0;
}
