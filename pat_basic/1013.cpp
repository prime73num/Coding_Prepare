#include <cstdio>

const int MAXN = 10005;

int primes[MAXN];
int size = 0;

bool isPrime(int n){
  for(int i = 0; i<size; i++){
    if(n % primes[i] == 0) return false;
  }
  return true;
}

int main (int argc, char *argv[]) {
  int n, m;
  scanf("%d %d", &n, &m);
  primes[0] = 2;
  size++;
  for(int i = 3; size < m;i++ ){
    if(!isPrime(i))
      continue;
    primes[size] = i;
    size++;
  }
  for(int i = n; i<m; i++){
    if((i-n+1) % 10 == 0){
      printf("%d\n", primes[i-1]);
    } else {
      printf("%d ", primes[i-1]);
    }
  }
  printf("%d\n", primes[m-1]);
  return 0;
}
