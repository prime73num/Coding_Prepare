#include <cstdio>


bool isPrime(int n){
  if(n < 2) return false;
  for(int i = 2; i*i <= n; i++){
    if(n%i==0) return false;
  }
  return true;
}

int reverse(int n, int radix){
  int res = 0;
  while (n > 0) {
    res = res * radix + n%radix;
    n/=radix;
  }
  return res;
}

int main (int argc, char *argv[]) {
  int n, radix;
  while (true) {
    scanf("%d", &n);
    if(n < 0) break;
    scanf("%d", &radix);
    int rev = reverse(n, radix);
    if(isPrime(n) && isPrime(rev)){
      printf("Yes\n");
    } else {
      printf("No\n");
    }
  }
  return 0;
}
