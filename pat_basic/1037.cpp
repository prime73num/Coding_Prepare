#include <cstdio>

int main (int argc, char *argv[]) {
  int pg, ps, pk;
  int ag, as, ak;
  scanf("%d.%d.%d %d.%d.%d", &pg, &ps, &pk, &ag, &as, &ak);
  int a = pk + ps*29 + pg*29*17;
  int b = ak + as*29 + ag*29*17;
  int diff = b - a;
  bool neg = false;
  if( diff < 0){
    neg = true;
    diff = -diff;
  }
  if(!neg){
    printf("%d.%d.%d", diff/(17*29), diff/29 % 17, diff % 29);
  } else {
    printf("-%d.%d.%d", diff/(17*29), diff/29 % 17, diff % 29);
  }
  return 0;
}
