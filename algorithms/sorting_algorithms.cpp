// a collection of the sorting algorithms I've met.

// BubleSort: a most simple way to sort a series of numbers.
// but not so efficient.
// @Param numbers: the array pointer storing the numbers
// @Param begin, end: show the range we need to sort.(begin <= i < end)
void BubleSort(int *numbers, int begin, int end) {
  for (int i = begin; i < end; i++) {
    for (int j = end - 1; j > i; j--) {
      if (numbers[j] < numbers[j - 1]) {
        int tmp = numbers[j - 1];
        numbers[j - 1] = numbers[j];
        numbers[j] = tmp;
      }
    }
  }
}

// SelectionSort: a unstable sorting algorithm.
// @Param numbers: the array pointer storing the numbers
// @Param begin, end: show the range we need to sort.(begin <= i < end)
void SelectionSort(int* numbers, int begin, int end) {
  for (int i = begin; i < end; i++) {
    // suppose the index of the number is i, and the left of i is sorted.
    // then find the mininum of the rest and exchange it with numbers[i].
    int min = i;
    for (int j = i + 1; j < end; j++) {
      if (numbers[j] < numbers[min]) min = j;
    }

    // exchange
    int temp = numbers[min];
    numbers[min] = numbers[i];
    numbers[i] = temp;
  }
}

// QuickSort.Just to put the numbers smaller than x on the left
// and the bigger on the right.
// @Param numbers: the array pointer storing the numbers
// @Param begin, end: show the range we need to sort.(begin <= i < end)
void QuickSort(int *numbers, int head, int end) {
  int t, i = head, j = end, x = numbers[(i + j) / 2];
  do {
    while (x > numbers[i]) i++;
    while (x < numbers[j]) j--;
    if (i <= j) {
      temp = numbers[i];
      numbers[i] = numbers[j];
      numbers[j] = temp;
      i++; j--;
    }
  } while (i <= j);
  if (i < end) quick_sort(numbers, i, end);     // sort the left
  if (head < j) quick_sort(numbers, head, j);   // sort the right
}
