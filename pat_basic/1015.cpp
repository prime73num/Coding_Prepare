#include <cstdio>
#include <algorithm>


struct stu{
  int id;
  int de;
  int cai;
}S[100000];
int hline;

int level(stu s);

bool cmp(stu l, stu r){
  if(level(l) != level(r))
    return level(l) > level(r);
  int suml = l.de + l.cai;
  int sumr = r.de + r.cai;
  if(suml!=sumr)
    return suml > sumr;
  if(l.de!=r.de)
    return l.de > r.de;

  return l.id < r.id;
}
int level(stu s){
  if(s.de >= hline && s.cai >= hline)
    return 5;
  if(s.de >= hline && s.cai < hline)
    return 4;
  if(s.de >= s.cai)
    return 3;
  return 2;
}

int main (int argc, char *argv[]) {
  int n, l, h;
  scanf("%d %d %d", &n, &l, &h);
  hline = h;
  int count = 0;
  for(int i = 0; i<n; i++){
    stu temp;
    scanf("%d %d %d", &temp.id, &temp.de, &temp.cai);
    if(temp.de < l || temp.cai < l)
      continue;
    S[count++] = temp;
  }
  std::sort(S, S+count, cmp);
  printf("%d\n", count);
  for(int i = 0; i<count; i++){
    printf("%d %d %d\n", S[i].id, S[i].de, S[i].cai);
  }
  return 0;
}
