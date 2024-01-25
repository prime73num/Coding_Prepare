#include <algorithm>
#include <climits>
#include <cstdio>

struct stu {
  int id;
  int grade[4];
  int rank;
  int bestrank;
  int row;
} S[2000];

char mp[] = "EMCA";
int row;
bool cmp(stu l, stu r){
  return l.grade[row] > r.grade[row];
}

int main(int argc, char *argv[]) {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; i++) {
    scanf("%d %d %d %d", &S[i].id, &S[i].grade[2], &S[i].grade[1], &S[i].grade[0]);
    S[i].grade[3] = S[i].grade[0] + S[i].grade[1] + S[i].grade[2];
    S[i].bestrank = INT_MAX;
  }
  for(int i = 0; i<4; i++){
    row = i;
    std::sort(S, S+n, cmp);
    S[0].rank = 1;
    S[0].bestrank = 1;
    S[0].row = row;
    for(int j = 1; j<n; j++){
      if(S[j].grade[row] != S[j-1].grade[row]){
        S[j].rank = j+1;
      } else {
        S[j].rank = S[j-1].rank;
      }
      if(S[j].rank <= S[j].bestrank){
        S[j].bestrank = S[j].rank;
        S[j].row = row;
      }
    }
  }
  for(int i = 0; i<m; i++){
    int id;
    scanf("%d", &id);
    int idx = -1;
    for(int j = 0; j<n; j++){
      if(id == S[j].id){
        idx = j;
        break;
      }
    }
    if(idx == -1){
      printf("N/A\n");
    } else {
      printf("%d %c\n", S[idx].bestrank, mp[S[idx].row]);
    }
  }
  return 0;
}
