#define MAX(x, y) (x) >= (y) ? (x) : (y)

// Least Common Multiple
// @Param m, n: the 2 numbers the LCM of which is to be found.
int LCM(int m, int n) {
  int multiple = MAX(m, n);       // get the bigger
  while (true) {
    // the first multiple met is the LCM of m, n
    if (multiple%m == 0 && multiple%n == 0) break;
    multiple++;
  }

  return multiple;
}

// a simplified version using GCD.
int LCM(int a, int b) {
  int GCD = GCD_recusion(a, b);
  int quotientA = a / GCD;
  int quotientB = b / GCD;
  int multiple = quotientA * quotientB * GCD;
  return multiple;
}
