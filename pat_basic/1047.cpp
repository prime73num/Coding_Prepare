#include <cstdio>

int team_score_sum[1005];

int main (int argc, char *argv[]) {
  int n;
  scanf("%d", &n);
  for(int i = 0; i<n; i++){
    int team, id, score;
    scanf("%d-%d %d", &team, &id, &score);
    team_score_sum[team] += score;
  }
  int idx = 0;
  for(int i = 1; i<=1000; i++){
    if(team_score_sum[i] > team_score_sum[idx])
      idx = i;
  }
  printf("%d %d", idx, team_score_sum[idx]);
  return 0;
}
