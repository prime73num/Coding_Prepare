#include <cstdio>

int stack[1009];
int p;
int max;
int s, push_num;

bool push(){
  if(s > push_num)
    return false;
  if(p>=max)
    return false;
  stack[p] = s;
  s++;
  p++;
  return true;
}
int top(){
  if(p==0)
    return -1;
  return stack[p-1];
}
int pop(){
  if(p==0)
    return -1;
  p--;
  return stack[p];
}

bool check(){
  bool res = true;
  for(int i = 0; i<push_num; i++){
    int output;
    scanf("%d", &output);
    if(!res)
      continue;
    while (top() != output && res) {
      if(!push()){
        res = false;
        break;
      }
    }
    pop();
  }
  return res;
}

int main (int argc, char *argv[]) {
  int m, n, k;
  scanf("%d %d %d", &m, &n, &k);
  max = m;
  for(int i = 0; i<k; i++){
    s = 1;
    push_num = n;
    p = 0;
    if(check()){
      printf("YES\n");
    } else {
      printf("NO\n");
    }
  }
  return 0;
}
