#include <cstdio>
#include <climits>


struct sign{
  char id[16];
  int signin;
  int signout;
};

int main (int argc, char *argv[]) {
  int n;
  scanf("%d", &n);
  sign in, out;
  in.signin = INT_MAX;
  out.signout = -1;
  for(int i = 0; i<n; i++){
    sign temp;
    int inh,inm,ins;
    int outh,outm,outs;
    scanf("%s %d:%d:%d %d:%d:%d", temp.id, &inh, &inm, &ins, &outh, &outm, &outs);
    temp.signin = inh * 3600 + inm * 60 + ins;
    temp.signout = outh * 3600 + outm * 60 + outs;
    if(temp.signin < in.signin)
      in = temp;
    if(temp.signout > out.signout)
      out = temp;
  }
  printf("%s %s", in.id, out.id);
  return 0;
}
