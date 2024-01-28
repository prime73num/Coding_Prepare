#include <algorithm>
#include <cstdio>


struct mooncake{
  float sum;
  float total_price;
}mlist[1003];

bool cmp(mooncake left, mooncake right){
  float a1 = left.total_price * right.sum;
  float a2 = right.total_price * left.sum;
  return a1 > a2;
}

int main (int argc, char *argv[]) {
  int n;
  float capcity;
  scanf("%d %f", &n, &capcity);
  for(int i = 0; i<n; i++){
    float temp;
    scanf("%f", &temp);
    mlist[i].sum = temp;
  }
  for(int i = 0; i<n; i++){
    float temp;
    scanf("%f", &temp);
    mlist[i].total_price = temp;
  }
  std::sort(mlist, mlist+n, cmp);
  float sum = 0;
  int idx = 0;
  while (capcity != 0 && idx < n) {
    if(capcity >= mlist[idx].sum){
      sum += mlist[idx].total_price;
      capcity -= mlist[idx].sum;
      idx++;
    } else {
      float price =  mlist[idx].total_price /mlist[idx].sum;
      sum += price * capcity;
      capcity = 0;
      idx++;
    }
  }
  printf("%.2f", sum);
  return 0;
}

