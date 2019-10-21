#include <stdio.h>
#include <stdlib.h>

#define M 1000000007

long long mod_mult(long long a, long long b) {
  return ((a % M) * (b % M)) % M;
}

long long square(long long x) {
  return mod_mult(x, x);
}

long long eleva(long long base, long long exp) {
  if(exp == 0) 
    return 1;
  else if (exp == 1) 
    return base;
  else if (exp % 2 == 0) 
    return square(eleva(base, exp / 2));
  else 
    return base * eleva(base, exp - 1);
}

int main() {
  long long n, e, result;

  scanf("%lld %lld", &n, &e);
  result = eleva(n, e);
  printf("%lld\n", result);
  return 0;
}
