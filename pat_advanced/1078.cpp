#include <cstdio>
int hashtable[10010];
int H;

bool isPrime(int n) {
  if (n < 2)
    return false;
  for (int i = 2; i * i <= n; i++) {
    if (n % i == 0)
      return false;
  }
  return true;
}

int hashF(int a) {
  int i;
  for (i = 0; i < H; i++) {
    if (hashtable[(a + i * i) % H] == -1)
      break;
  }
  if (i == H)
    return -1;
  hashtable[(a + i * i) % H] = a;
  return (a + i * i) % H;
}

int findsize(int size) {
  for (;; size++) {
    if (isPrime(size))
      break;
  }
  return size;
}
int main(int argc, char *argv[]) {
  int size, n;
  scanf("%d %d", &size, &n);
  size = findsize(size);
  H = size;
  for (int i = 0; i < size; i++) {
    hashtable[i] = -1;
  }
  for (int i = 0; i < n; i++) {
    int temp;
    scanf("%d", &temp);
    int pos = hashF(temp);
    if (pos == -1) {
      printf("-");
    } else {
      printf("%d", pos);
    }
    if (i == n - 1)
      printf("\n");
    else
      printf(" ");
  }
  return 0;
}
