#include <algorithm>
#include <cstdio>
#include <cstring>
#include <sys/resource.h>

struct rec{
  char name[21];
  int day,hour, min;
  bool online;
}Rlist[1000];
int fare[12];

bool cmp(rec l, rec r){
  int d = strcmp(l.name, r.name);
  if(d != 0)
    return d<0;
  if(l.day != r.day)
    return l.day < r.day;
  if(l.hour != r.hour)
    return l.hour < r.hour;
  return l.min < r.min;
}

void count_time_money(rec on, rec off, int& time, int& money){
  rec temp = on;
  while (temp.day < off.day || temp.hour < off.hour || temp.min < off.min) {
    time++;
    money += fare[temp.hour];
    if(temp.min >= 60){
      temp.min = 0;
      temp.hour++;
    }
    if(temp.hour >= 24){
      temp.hour = 0;
      temp.day++;
    }
  }
}


int main (int argc, char *argv[]) {
  for(int i = 0; i<12; i++){
    scanf("%d", &fare[i]);
  }
  int n;
  scanf("%d", &n);
  for(int i = 0; i<n; i++){
    int mon;
    char temp[10];
    scanf("%s %d:%d:%d:%d %s", Rlist[i].name, &mon, &Rlist[i].day, &Rlist[i].hour, &Rlist[i].min, temp);
    if(strcmp(temp, "oo-line") == 0){
      Rlist[i].online = true;
    } else {
      Rlist[i].online = false;
    }
  }
  std::sort(Rlist, Rlist+n, cmp);
  char name[21] = "";
  for(int i = 0; i<n; i++){
    if(Rlist[i].name != name){
      name = Rlist[i].name;
    }
  }
  return 0;
}
