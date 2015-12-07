// by Junjie Huang@SYSU(SNO:13331087)
// calculate the first 10000 elements of Finonacci series
#define MAX_SIZE 10000

int fi[MAX_SIZE] = { 0 };     // array storing the elements

// calculation
void fibonacci() {
  fi[0] = fi[1] = 1;
  for (int i = 2; i < MAX_SIZE; i++) fi[i] = fi[i-1] + fi[i-2];
}
