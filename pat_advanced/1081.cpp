#include <cstdio>
#include <cstdlib>

typedef long long LL ;

struct Fraction{
  LL up, down;
};

LL gcd(LL a, LL b){
  return b==0? a:gcd(b, a%b);
}

void reduce(Fraction& a){
  LL temp = gcd(abs(a.up), a.down);
  a.up /= temp;
  a.down /= temp;
}

Fraction add(Fraction a, Fraction b){
  Fraction res;
  res.down = a.down * b.down;
  res.up = a.up*b.down + a.down*b.up;
  reduce(res);
  return res;
}

int main (int argc, char *argv[]) {
  int n;
  scanf("%d", &n);
  Fraction res;
  res.up = 0;
  res.down = 1;
  for(int i = 0; i<n; i++){
    Fraction temp;
    scanf("%lld/%lld", &temp.up, &temp.down);
    res = add(res, temp);
  }
  if(res.down == 1){
    printf("%lld\n", res.up);
  } else if(res.up > res.down){
    printf("%lld %lld/%lld\n", res.up/res.down, res.up%res.down, res.down);
  } else {
    printf("%lld/%lld\n", res.up, res.down);
  }
  return 0;
}
