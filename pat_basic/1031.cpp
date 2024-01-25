#include <cstdio>
#include <iostream>

int main (int argc, char *argv[]) {
  int n;
  scanf("%d\n", &n);
  char temp[19];
  int weight[] = {7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2};
  char mp[] = "10X98765432";
  bool all_passed = true;
  for(int i = 0; i<n; i++){
    std::cin.getline(temp, 19);
    int sum = 0;
    int passed = true;
    for(int i = 0; i<17; i++){
      int num = temp[i] - '0';
      if(num>9 || num<0) {
        passed = false;
        break;
      }
      sum += num*weight[i];
    }
    if(!passed || mp[sum%11] != temp[17]){
      printf("%s\n", temp);
      all_passed = false;
    }
  }
  if(all_passed){
    printf("All passed\n");
  }
  return 0;
}
