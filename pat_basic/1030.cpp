#include <algorithm>
#include <cstdio>

int nums[100003];

int main (int argc, char *argv[]) {
  int n,p;
  scanf("%d %d", &n, &p);
  for(int i = 0; i<n; i++){
    scanf("%d", &nums[i]);
  }
  std::sort(nums, nums+n);
  int s = 0, e = 0;
  int max = 1;
  for(s = 0; s<n; s++){
    long long multi = (long long)nums[s]*p;
    while (e<n && nums[e] <= multi) e++;
    if(e-s > max)
      max = e-s;
  }
  printf("%d\n", max);
  return 0;
}
