#include <cstdio>
#include <cstring>

int hashmp[128];
char line[10003];
char mp[] = "PATest";

int main(int argc, char *argv[]) {
  scanf("%s", line);
  int len = strlen(line);
  for (int i = 0; i < len; i++) {
    hashmp[line[i]]++;
  }
  int count[6];
  for (int i = 0; i < 6; i++) {
    count[i] = hashmp[mp[i]];
  }
  while (count[0] > 0 || count[1] > 0 || count[2] > 0 || count[3] > 0 ||
         count[4] > 0 || count[5] > 0) {
    for (int i = 0; i < 6; i++) {
      if(count[i] > 0){
        printf("%c", mp[i]);
        count[i]--;
      }
    }
  }
  return 0;
}
