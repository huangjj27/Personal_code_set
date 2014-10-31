// Copyright (c) 2014 Junjie_Huang@SYSU(SNO:13331087). All Rights Reserved.
// 求组合数

#include "stdio.h"

#define ERROR -1

// 求一个非负整数的阶乘
long int factorial(int n) {
  long int result = 1;
  int i;
  for (i = 1; i <= n; i++) result *= i;  // 从1乘到n

  return result;
}

// 求从n个数中取m个数所能产生的组合数。
long int Combinatorial(int m, int n) {
  long int numerator;    // 分子
  long int denominator;  // 分母

  // 如果n为零或者m比n大，或者m、n为负数，这些都是错误的情况，返回一个错误标示
  if (m > n || n <= 0 || m < 0) return ERROR;

  // 其他情况计算结果。
  numerator = factorial(n);
  denominator = factorial(n - m) * factorial(m);

  return numerator / denominator;
}

int main() {
  int test_cases;  // 测试样例数

  // for(初始条件; 判断条件; 尾执行语句) {...}
  for (scanf("%d", &test_cases); test_cases; test_cases--) {
    long int m, n;
    scanf("%ld %ld", &m, &n);
    if (Combinatorial(m, n) == ERROR) {
      printf("Invalid input!\n");
    } else {
      printf("%ld\n", Combinatorial(m, n));
    }
  }

  return 0;
}
