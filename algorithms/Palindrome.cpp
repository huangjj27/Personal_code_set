// judges if a long integer is a palindrome(回文数)
// @n: the integer to be judged
bool int Palindrome(long int n) {
  int v = n;
  // reverse the integer n
  for (int u = 0; v; v /= 10) {
    u = 10 * u + v % 10;
  }
  return (u == n ? true : false);
}
