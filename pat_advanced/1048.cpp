#include <algorithm>
#include <cstdio>
const int MAXN = 100005;
int nlist[MAXN];

int main (int argc, char *argv[]) {
  int n, pay;
  scanf("%d %d", &n, &pay);
  for(int i = 0; i<n; i++){
    scanf("%d", &nlist[i]);
  }
  std::sort(nlist, nlist+n);
  int s, e;
  bool found = false;
  for(s = 0, e=n-1; s<e && s<n; s++){
    while (s<e && nlist[s]+nlist[e] > pay) e--;
    int sum = nlist[s] + nlist[e];
    if(s != e && sum==pay){
      found = true;
      break;
    }
  }
  if(found)
    printf("%d %d\n", nlist[s], nlist[e]);
  else
   printf("No Solution\n");
  
  return 0;
}
