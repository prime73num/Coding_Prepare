#include <cstdio>
#include <stdio.h>


int main (int argc, char *argv[]) {
  
  int n;
  scanf("%d", &n);

  int win = 0, tie = 0, lose = 0;
  int a[] = {0, 0, 0};
  int b[] = {0, 0, 0};
  while (n--) {
    getchar();
    int anum, bnum;
    char ach, bch;
    scanf("%c %c", &ach, &bch);
    if(ach == 'C'){
      anum = 0;
    }
    if(ach == 'J'){
      anum = 1;
    }
    if(ach == 'B'){
      anum = 2;
    }
    if(bch == 'C'){
      bnum = 0;
    }
    if(bch == 'J'){
      bnum = 1;
    }
    if(bch == 'B'){
      bnum = 2;
    }

    if(anum == bnum){
      tie++;
      continue;
    }
    if((anum+1) % 3 == bnum){
      a[anum]++;
      win++;
    } else {
      b[bnum]++;
      lose++;
    }
  }
  printf("%d %d %d\n", win, tie, lose);
  printf("%d %d %d\n", lose, tie, win);
  char wina, winb;
  if(a[1] >= a[0] && a[1] >= a[2]){
    wina = 'J';
  }
  if(a[0] >= a[1] && a[0] >= a[2]){
    wina = 'C';
  }
  if(a[2] >= a[1] && a[2] >= a[0]){
    wina = 'B';
  }

  if(b[1] >= b[0] && b[1] >= b[2]){
    winb = 'J';
  }
  if(b[0] >= b[1] && b[0] >= b[2]){
    winb = 'C';
  }
  if(b[2] >= b[1] && b[2] >= b[0]){
    winb = 'B';
  }
  printf("%c %c\n", wina, winb);
  return 0;
}
