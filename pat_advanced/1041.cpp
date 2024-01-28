#include <cstdio>



int count[10005];
int nums[100000];
int main (int argc, char *argv[]) {
  int n;
  scanf("%d", &n);
  for(int i = 0; i<n; i++){
    int temp;
    scanf("%d", &temp);
    nums[i] = temp;
    count[temp]++;
  }
  int idx = 0;
  for(idx = 0; idx<n; idx++){
    if(count[nums[idx]] == 1)
      break;
  }
  if(idx == n)
    printf("None\n");
  else
   printf("%d\n", nums[idx]);
  return 0;
}
