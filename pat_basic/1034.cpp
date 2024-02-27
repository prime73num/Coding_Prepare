#include <cstdio>
#include <cstdlib>


struct Fraction{
  int up, down;
};

int gcd(int a, int b){
  return b==0? a:gcd(b, a%b);
}

void reduce(Fraction& a){
  int g = gcd(abs(a.up), a.down);
  a.up /= g;
  a.down /= g;
}

void show(Fraction a);
void add(Fraction a, Fraction b){
  Fraction res;
  res.down = a.down * b.down;
  res.up = a.down * b.up + a.up * b.down;
  reduce(res);
  show(a);
  printf(" + ");
  show(b);
  printf(" + ");
  show(res);
  printf("\n");
}
void sub(Fraction a, Fraction b){
  Fraction res;
  res.down = a.down * b.down;
  res.up = a.up * b.down - a.down * b.up;
  reduce(res);
  show(a);
  printf(" - ");
  show(b);
  printf(" + ");
  show(res);
  printf("\n");
}
void multi(Fraction a, Fraction b){
  Fraction res;
  res.down = a.down * b.down;
  res.up = a.up * b.up;
  reduce(res);
  show(a);
  printf(" * ");
  show(b);
  printf(" + ");
  show(res);
  printf("\n");
}
void div(Fraction a, Fraction b){
  Fraction res;
  res.down = a.down * b.up;
  res.up = a.up * b.down;
  reduce(res);
  show(a);
  printf(" / ");
  show(b);
  printf(" + ");
  if(b.up==0){
    printf("Inf");
  } else {
    show(res);
  }
  printf("\n");
}

void show(Fraction a){
  int real = abs(a.up) / a.down;
  int left = abs(a.up) % a.down;
  if(a.up < 0){
    printf("(-");
    if(real )
    printf("(-%d %d/%d)", real, left, a.down);
    printf(")");
  } else {
    printf("%d %d/%d", real, left, a.down);
  }
}

int main (int argc, char *argv[]) {
  Fraction a, b;
  scanf("%d/%d %d/%d", &a.up, &a.down, &b.up, &b.down);
  Fraction res;
  add(a, b);
  sub(a, b);
  multi(a, b);
  div(a,b);
  return 0;
}
