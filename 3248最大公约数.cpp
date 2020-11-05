/*************************************************************************
*File Name: 3248最大公约数.cpp
*Author: LiShiJie
*mail: 2659002865@qq.com
*Created Time: Thu Nov  5 16:09:11 2020
 ************************************************************************/

#include <stdio.h>

int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}

int main() {
    int m, n;
    while (~scanf("%d%d", &m, &n)) {
        printf("%d\n", gcd(m, n));
    }
    return 0;
}
