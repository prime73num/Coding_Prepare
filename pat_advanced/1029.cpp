#include <cstdio>

const int MAXN = 200005;
int s1[MAXN], s2[MAXN];


int main (int argc, char *argv[]) {
  int n,m;
  scanf("%d", &n);
  for(int i = 0; i<n; i++){
    scanf("%d", &s1[i]);
  }
  scanf("%d", &m);
  for(int i = 0; i<m; i++){
    scanf("%d", &s2[i]);
  }
  int target = (m+n+1)/2;
  int a = 0, b = 0;
  int res;
  while (target--) {
    if(b==m || (a<n && s1[a] < s2[b])){
      res = s1[a];
      a++;
    } else {
      res = s2[b];
      b++;
    }
  }
  printf("%d", res);
  return 0;
}
