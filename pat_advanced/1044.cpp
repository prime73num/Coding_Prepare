#include <climits>
#include <cstdio>

const int MAXN = 100005;
int nlist[MAXN];

int main (int argc, char *argv[]) {
  int n, pay;
  scanf("%d %d", &n, &pay);
  nlist[0] = 0;
  for(int i = 1; i<=n; i++){
    int temp;
    scanf("%d", &temp);
    nlist[i] = temp + nlist[i-1];
  }
  int s = 1, e = 1;
  int min = INT_MAX;
  for(s = 1; s<=n; s++){
    while (e<=n && nlist[e] - nlist[s-1] < pay) e++;
    int sum = nlist[e] - nlist[s-1];
    if(sum >= pay && sum < min)
      min = sum;
  }
  e = 1;
  for(s = 1; s<=n; s++){
    while (e<=n && nlist[e] - nlist[s-1] < min) e++;
    int sum = nlist[e] - nlist[s-1];
    if(sum==min)
      printf("%d-%d\n", s, e);
  }

  return 0;
}
