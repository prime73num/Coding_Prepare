#include <algorithm>
#include <cstdio>

struct gas_station{
  int coord;
  float price;
}glist[500];
int min[500];

bool cmp(gas_station left, gas_station right){
  return left.coord < right.coord;
}
int main (int argc, char *argv[]) {
  int tank, dis, dpu, gas_num;
  scanf("%d %d %d %d", &tank, &dis, &dpu, &gas_num);
  for(int i = 0; i<gas_num; i++){
    scanf("%f %d", &glist[i].price, &glist[i].coord);
  }
  std::sort(glist, glist+gas_num, cmp);
  int max_dis = tank * dpu;
  float sum = 0;
  int total_dis = 0;
  int idx = 0;
  while (idx < gas_num && total_dis < dis) {
    int min = idx + 1;
    int max_coord = glist[idx].coord + max_dis;
    for(int i = idx+1;i < gas_num && glist[i].coord <=max_coord; i++) {
      if(glist[i].price < glist[min].price)
        min = i;
    }
  }
  return 0;
}
