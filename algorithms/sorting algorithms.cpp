// a collection of the sorting algorithms I've met.

// BubleSort: a most simple way to sort a series of numbers.
// but not so efficient.
// @Param number[]: the array storing the numbers
// @Param begin, end: show the range we need to sort.(begin <= i < end)
void BubleSort(int number[], int begin, int end) {
  for (int i = begin; i < end; i++) {
    for (int j = end - 1; j > i; j--) {
      if (number[j] < number[j - 1]) {
        int tmp = number[j - 1];
        number[j - 1] = number[j];
        number[j] = tmp;
      }
    }
  }
}

// quick sort.Just to put the numbers smaller than x on the left
// and the bigger on the right.
void quick_sort(int *a, int HEAD, int END) {
  int t, i = HEAD, j = END, x = a[(i + j) / 2];
  do {
    while (x > a[i]) i++;
    while (x < a[j]) j--;
    if (i <= j) {
      t = a[i];
      a[i] = a[j];
      a[j] = t;
      i++; j--;
    }
  } while (i <= j);
  if (i < END) quick_sort(a, i, END);
  if (HEAD < j) quick_sort(a, HEAD, j);
}
