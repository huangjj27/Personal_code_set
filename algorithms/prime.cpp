// judges if a long integer is a prime
// @n: the integer to be judged
bool int Prime(long int n) {
  // divides each number less than the positive square root of n
  // 1 can always be divided which is not considered
  // as defination of a prime, and thus we begin with 2.
  // because of the duality, if a factor of n less than its square root found,
  // another bigger will also found.
  // on the other hand,
  // if none of a factor of n less than its square root found,
  // neither will bigger.
  for (i = 2; i*i <= n; i++) {
    if (n%i == 0) return false;       // if a factor is found, n is not a prime
  }
  return true;        // no factor is found, n is a prime.
}
