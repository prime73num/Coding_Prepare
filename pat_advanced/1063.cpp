#include <cstdio>
#include <set>

std::set<int> slist[55];

void compare(int a, int b){
  std::set<int> &aset = slist[a];
  std::set<int> &bset = slist[b];
  int total = aset.size() + bset.size();
  int common = 0;
  for(auto it = aset.begin(); it != aset.end(); it++){
    if(bset.find(*it) != bset.end()) common++;
  }
  total -= common;
  printf("%.1f%%\n", (float)common*100/total);
}

int main (int argc, char *argv[]) {
  int n;
  scanf("%d", &n);
  for(int i = 0; i<n; i++){
    int num;
    scanf("%d", &num);
    for(int j = 0; j<num; j++){
      int temp;
      scanf("%d", &temp);
      slist[i].insert(temp);
    }
  }

  int query;
  scanf("%d", &query);
  for(int i = 0; i<query; i++){
    int a, b;
    scanf("%d %d", &a, &b);
    compare(a-1, b-1);
  }
  return 0;
}
