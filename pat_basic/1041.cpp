#include <cstdio>


const int MAXN = 1000;
long long id[MAXN+1];
int pos[MAXN+1];
int main (int argc, char *argv[]) {
  int n;
  scanf("%d", &n);
  for(int i = 0; i<n; i++){
    long long id_temp;
    int idx, pos_temp;
    scanf("%lld%d%d", &id_temp, &idx, &pos_temp);

    id[idx] = id_temp;
    pos[idx] = pos_temp;
  }
  scanf("%d", &n);
  for(int i = 0; i<n; i++){
    int temp;
    scanf("%d", &temp);
    printf("%016lld %d\n", id[temp], pos[temp]);
  }
  return 0;
}
