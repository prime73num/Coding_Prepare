#include <cstdio>

bool isPrime(int a){
  for(int i = 2; i*i <= a; i++){
    if(a%i == 0) return false;
  }
  return true;
}

int main (int argc, char *argv[]) {
  int n;
  int count = 0;
  scanf("%d", &n);
  for(int i = 3; i+2 <= n; i+=2){
    if(isPrime(i) && isPrime(i+2)) count++;
  }
  printf("%d", count);
  return 0;
}
