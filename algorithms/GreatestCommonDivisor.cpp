#define MIN(x, y) (x) <= (y) ? (x) : (y)      // finds the smaller

// Greatest Common Divisor
// @Param m, n: the two numbers of which the GCD is to find.
int GCD(int m, int n) {
  int divisor = MIN(m, n)         // gets the smaller of m, n as the divisor
  for (; divisor; divisor--) {
    // the first divisor met of both is the GCD
    if (m%divisor == 0 && n%divisor == 0) break;
  }

  return divisor;
}

// a version using successive division.
// each time get the smaller number min
// and the remainder rem of the bigger dividing the smaller.
// then let min become the bigger and rem the smaller, redo the step again
// until the remmainder is zero. and the min when rem is 0 is the GCD.
int GCD_recusion(int a, int b) {
  if (b == 0) return a;
  return GCD(b, a%b);  // Recursion.
}
