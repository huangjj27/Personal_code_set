// Copyright(C) 2014 Junjie Huang@SYSU (SNO: 13331087). All Rights Reserved.
// Junjie Huang is a student majoring in Software Engineering,
// from the School of Software, SUN YAT-SEN UNIVERSITY, GZ 510006, P. R. China.
// Email: 349373001@qq.com
// QQ: 34937301.

//1.交作业常用标准头及程序
#include<stdio.h>
scanf("%d", &a)
printf("%d", a);
getchar()
gets()
puts()
snprintf(char*, sizeof(char), const char)
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
isalpha()
iscntrl()
isdigit()
isgraph()  //  determine whether the character can be printed.(not space)
islower()
isupper()
tolower()
toupper()
isalnum() //  determine whether the character is alphebet or number.
isprint() //  determine whether the character can be printed.
#include<string.h>
strstr(char*, char*)
strncmp(char*, char*, size)
strncpy(char*, const char)
memset(char*, '\0', sizeof(char*)// To reset the array.
strrev(char* a);
swab(char*, char*);
#define swap(m, n) m ^= n ^= m ^= n
#define max(a, b) a > b ? a : b
//以上部分为c文件头

// FILE input and output

FILE* fptr_in;
FILE* fptr_out;

fptr_in = fopen("C:\\Users\\Marvel\\Desktop\\text.txt", "r");
fptr_out = fopen("C:\\Users\\Marvel\\Desktop\\out.txt", "w");

fclose(fptr_in);
fclose(fptr_out);

#include<algorithm>


int main() {
    int t, n, N;
    scanf("%d", &t);
    for (; t; t--) {
        scanf("%d", &n);
    }
    printf("\n");
    return 0;
}

//2.回文数判断算法
long int Palindrome(long int n) {
    int u, v = n;
    for (u = 0; v; v /= 10) {
        u = 10 * u + v % 10;
    }
    return (u == n ? 1 : 0);
}

//3.质数判断算法
long int Prime(long int n) {
    int i;
    for (i = 2; i*i <= n; i++) {
        if (n%i == 0) return 0;
    }
    return 1;
}

//4.从1直到这个数之中的3的倍数之和
int sumMultipliedBy3(int n) {
    if (n >= 1 && n <= 32767) {
        int sum = 0, u;
        for (u = 1; 3 * u <= n; u++) {
            sum += 3 * u;
        }
        return sum;
    }
}

//5.计算出刚好小于或等于这个正整数的斐波那契数列项的值（包括0）
int Fibonacci(int n) {
    int a = 0, b = 1, c = 0, d;
    if (!n) return 1;
    while (c <= n) {
        d = c;
        c = a + b;
        a = b;
        b = c;
    }
    return d;
}

//6.海伦公式
double Halen() {
    double x1, y1, x2, y2, x3, y3,
        a, b, c,
        p, s;
    a = sqrt((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2));
    b = sqrt((x1 - x3)*(x1 - x3) + (y1 - y3)*(y1 - y3));
    c = sqrt((x3 - x2)*(x3 - x2) + (y3 - y2)*(y3 - y2));
    p = (a + b + c) / 2;
    s = sqrt(p*(p - a)*(p - b)*(p - c));
    printf("%.2lf\n", s);
    return 0;
}

//7.两个班级人数及输入成绩比较平均成绩的算法
#include<stdio.h>

int main() {
    int i, j, t, n, m;
    float N, M, sumN, sumM;
    scanf("%d", &t);
    for (; t; t--) {
        scanf("%d %d", &i, &j);
        n = i; m = j;

        for (sumN = 0; i; i--) {
            scanf("%f", &N);
            sumN += N;
        }
        sumN /= n;

        for (sumM = 0; j; j--) {
            scanf("%f", &M);
            sumM += M;
        }
        sumM /= m;

        printf("%.2lf %.2lf\n", sumN, sumM);

        sumN == sumM ?
            printf("Equal\n") :
            (sumN > sumM ? printf("More\n") : printf("Less\n"));
    }

    return 0;
}

/* 8.守望者的逃离
恶魔猎手尤迪安野心勃勃，他背叛了暗夜精灵，率领深藏在海底的娜迦族企图叛变。
守望者在与尤迪安的交锋中遭遇了围杀，被困在一个荒芜的大岛上。为了杀死守望者，
尤迪安开始对这个荒岛施咒，这座岛很快就会沉下去。到那时，岛上的所有人都会遇难。
守望者的跑步速度为17m/s，以这样的速度是无法逃离荒岛的。庆幸的是守望者拥有闪
烁法术，可在1s内移动60m，不过每次使用闪烁法术都会消耗魔法值10点。守望者的魔
法值恢复的速度为4点/s，只有处在原地休息状态时才能恢复。
现在已知守望者的魔法初值M，他所在的初始位置与岛的出口之间的距离S，岛沉没的时间T。
你的任务是写一个程序帮助守望者计算如何在最短的时间内逃离荒岛，若不能逃出，
则输出守望者在剩下的时间内能走的最远距离。注意：守望者跑步、闪烁或休息活动均以秒(s)为单位，
且每次活动的持续时间为整数秒。距离的单位为米(m)。

输入的第一行为测试数据组数N (N <= 10)
输入包含多个测试数据，每个测试数据仅一行，包括空格隔开的三个非负整数M, S, T。
1 <= T <= 300000, 0 <= M <= 400, 1 <= S <= 10^7.

对每个测试数据输出两行：
第1行为字符串"Yes"或"No"（区分大小写），即守望者是否能逃离荒岛。
第2行包含一个整数。第一行为"Yes"（区分大小写）时表示守望者逃离荒岛的最短时间；
第一行为"No"（区分大小写）时表示守望者能走的最远距离。
相邻两个测试数据间用一个空行隔开。

样例输入输出：
输入：
2
39 200 4
36 255 10
输出：
No
197

Yes
6
*/

//示例1： 贪心算法
#include <stdio.h>
int main() {
    int i, m, s, t, T, S;
    scanf("%d", &i);
    while (i) {
        scanf("%d %d %d", &m, &s, &t);
        T = t;
        S = s;
        while (m / 10 >= 1 && t >= 1) {
            m = m - 10;
            s = s - 60;
            t--;
        }
        while (m < 10 && t >= 1) {
            if (m == 0 && s > 102 && t >= 7) {
                t = t - 7;//当没有魔法值的时候各个情况找出最优算法，然后整合
                s = s - 120;//实际上是很机械的东西
            }
            if (m == 1 && s > 102 && t >= 7) {
                t = t - 7;
                s = s - 120;
            }
            if (m == 2 && s > 34 && t >= 3) {
                t = t - 3;
                s = s - 60;
                m = 0;
            }
            if (m == 3 && s > 34 && t >= 3) {
                t = t - 3;
                s = s - 60;
                m = 1;
            }
            if (m == 4 && s > 34 && t >= 3) {
                t = t - 3;
                s = s - 60;
                m = 2;
            }
            if (m == 5 && s > 34 && t >= 3) {
                t = t - 3;
                s = s - 60;
                m = 3;
            }
            if (m == 6 && s > 17 && t >= 2) {
                t = t - 2;
                s = s - 60;
                m = 0;
            }
            if (m == 7 && s > 17 && t >= 2) {
                t = t - 2;
                s = s - 60;
                m = 1;
            }
            if (m == 8 && s > 17 && t >= 2) {
                t = t - 2;
                s = s - 60;
                m = 2;
            }
            if (m == 9 && s > 17 && t >= 2) {
                t = t - 2;
                s = s - 60;
                m = 3;
            }
            if (m == 0 && (s <= 102 || t < 7)) break;
            if (m == 1 && (s <= 102 || t < 7)) break;
            if (m == 2 && (s <= 34 || t < 3)) break;
            if (m == 3 && (s <= 34 || t < 3)) break;
            if (m == 4 && (s <= 34 || t < 3)) break;
            if (m == 5 && (s <= 34 || t < 3)) break;
            if (m == 6 && (s <= 17 || t < 2)) break;
            if (m == 7 && (s <= 17 || t < 2)) break;
            if (m == 8 && (s <= 17 || t < 2)) break;
            if (m == 9 && (s <= 17 || t < 2)) break;
        }
        while (t >= 1 && s > 0) {
            s = s - 17;
            t = t - 1;
        }
        if (s > 0) printf("No\n%d\n", S - s);
        else printf("Yes\n%d\n", T - t);
        i--;
    }
    return 0;
}

//简化算法（可以所短运行时间）
#include <stdio.h>
int main() {
    long n, t, m, s;
    scanf("%ld", &n);
    while (n--) {
        scanf("%ld %ld %ld", &m, &s, &t);
        long time = t;
        long distance = 0;
        while (t >= 0) {
            if (m >= 10) {
                m -= 10;
                distance += 60;
            } else if (s - distance <= 17 || t <= 6 && m < 2) {
                distance += 17;//其实就是合并相同情况
            } else if (s - distance <= 34 && m < 6
                || s - distance <= 102 && m < 2) {
                distance += 17;
            } else if (m + 4 * (t - 1) >= 10) {
                m += 4;
            } else {
                distance += 17;
            }
            t--;
            if (distance >= s) {
                printf("Yes\n%ld\n", time - t);
                break;
            }
            if (t == 0) {
                printf("No\n%ld\n", distance);
                break;
            }
        }
    }
    return 0;
}

//9.测量时间
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

clock_t start, finish;
double duration;
/* 测量一个事件持续的时间*/

start = clock();
// program
finish = clock();
duration = (double) (finish - start) / CLOCKS_PER_SEC;


//10.最大公约数(Greatest Common Divisor)算法
int GCD() {
    int m, n, M;
    scanf("%d %d", &m, &n);
    M = m <= n ? m : n;
    for (; M; M--) {
        if (m%M == 0 && n%M == 0) break;
    }
    printf("%d\n", M);
    return 0;
}

//11.最小公倍数(Least Common Multiple)算法
int LCM() {
    int m, n, M;
    scanf("%d %d", &m, &n);
    M = m >= n ? m : n;
    for (; M; M++) {
        if (M%m == 0 && M%n == 0) break;
    }
    printf("%d\n", M);
    return 0;
}

//12.蔡勒公式
int Zeller(int Y, int m, int d) {
    int Y, W,
        c, y, m, d;
    scanf("%d %d %d", &Y, &m, &d);
    y = Y % 100;
    c = Y / 100;

    if (m <= 2) {
        y--;
        m += 12;
    }

    if (Y > 1580) {
        W = y + y / 4 + c / 4 - 2 * c + 26 * (m + 1) / 10 + d - 1;//1580年10月4日以后
    } else if (Y < 1580) {
        W = y + y / 4 + c / 4 - 2 * c + 26 * (m + 1) / 10 + d + 2;//1580年10月15日以前
    } else if (Y == 1580) {
        if (m == 10) {
            if (d >= 5 && d <= 14) {
                printf("The date doesn't exist.\n");
                return 0;
            } else if (d < 5) {
                W = y + y / 4 + c / 4 - 2 * c + 26 * (m + 1) / 10 + d + 2;
            } else {
                W = y + y / 4 + c / 4 - 2 * c + 26 * (m + 1) / 10 + d - 1;
            }
        } else if (m < 10) {
            W = y + y / 4 + c / 4 - 2 * c + 26 * (m + 1) / 10 + d + 2;
        } else {
            W = y + y / 4 + c / 4 - 2 * c + 26 * (m + 1) / 10 + d - 1;
        }
    }
    W = (W % 7 + 7) % 7;
    printf("%d", W);
    printf("\n");
    return 0;
}

//冒泡排序
void* BubleSort() {
    int i, j, tmp, number[];

    for (i = 0; i < LENGTH; i++) {
        for (j = LENGTH - 1; j > i; j--) {
            if (number[j] < number[j - 1]) {
                tmp = number[j - 1];
                number[j - 1] = number[j];
                number[j] = tmp;
            }
        }
    }
}

//快速幂算法 位操作
int pow4(int x, long n, int p) {
    int result;

    if (n == 0) {
        return 1;
    } else {
        while (!(n & 1)) {
            n >>= 1;
            x = (x*x%p + p) % p;
        }
    }

    result = x;
    n >>= 1;

    while (n) {
        x = (x*x%p + p) % p;

        if (n & 1)
            result = (result*x%p + p) % p;

        n >>= 1;
    }

    return result;
}

//quick_pow
int quick_pow(int a, int b, int m) {
    long long result = 1, pow = a;
    while (b) {
        if (b & 1) result = (result*pow) % m;
        pow = (pow*pow) % m;
        b >>= 1;
    }
    return result;
}

//辗转相除法
int RollingDevision(int m, int n) {
    int temp;
    if (m < n) {
        temp = m;
        m = n;
        n = temp;
    }

    while (n) {
        temp = m%n;
        m = n;
        n = temp;
    }

    return m;
}


//GCD和LCM算法简化版
int GCD(int a, int b) {
    if (b == 0) return a;
    return GCD(b, a%b);  // Recursion.
}
int LCM(int a, int b) {
    return a / GCD(a, b) * b;
}

// to transform the demical numbers into hexademical ones.
#include<stdio.h>

int main() {
    // Declarations:
    // @Param i: the counter;
    // @Param m: to store the input number;
    // @Array n[]: to store every digit of the output number.
    // @Param sign: the sign of the number m.
    int i, m, sign, n[1000];

    scanf("%d", &m);  // input a number.

    //get the sign of the number m.
    if (m < 0) {
        printf("-");
        m = 0 - m;
    }

    // get every digit for the hexademical number, treat it as a character.
    for (i = 0; m; m /= 16, i++) {
        n[i] = m % 16;
        switch (n[i]) {
            case 10: n[i] = 'a'; break;
            case 11: n[i] = 'b'; break;
            case 12: n[i] = 'c'; break;
            case 13: n[i] = 'd'; break;
            case 14: n[i] = 'e'; break;
            case 15: n[i] = 'f'; break;
        }
    }

    //output the result,digit by digit.
    // to avoid the uncorrect output, we need to discuss
    //for different circustance.
    while (--i >= 0) {
        // when the digit is less than 10, output the digit directly.
        if (n[i] < 10) printf("%d", n[i]);
        // when the digit is a-f, output the digit as a character.
        else printf("%c", n[i]);
    }
    printf("/n");
    return 0;  // end the main fuction.
}

// 0-1 knapack problem.
int A(int i, int W) {
    if (!(i && W)) return 0;  // Here will get into dead loop.
    if (w[i] > W) return A(i - 1, W);
    if (w[i] <= W) {
        return A(i - 1, W) > v[i] + A(i - 1, W - w[i]) ?
            A(i - 1, W) : v[i] + A(i - 1, W - w[i]);
    }
}
// Corrected answer.
int A(int n, int W) {
    int i, j;
    int value[5000] = { 0 };
    for (i = 0; i < n; i++) {
        for (j = W; j >= w[i]; j--)
            value[j] = value[j] > value[j - w[i]] + v[i] ?
            value[j] : value[j - w[i]] + v[i];
    }
    return value[W];
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

int euler(int n) {
    int ret = 1, i;
    for (i = 2; i*i <= n; i++) {
        if (n%i == 0) {
            n /= i;
            ret *= i - 1;
            while (n%i == 0) {
                n /= i;
                ret *= i;
            }
        }
    }
    if (n > 1)
        ret *= n - 1;
    return ret;
}
