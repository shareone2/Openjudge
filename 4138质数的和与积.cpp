/*************************************************************************
*File Name: 4138质数的和与积.cpp
*Author: LiShiJie
*mail: 2659002865@qq.com
*Created Time: Thu Oct 29 16:41:32 2020
 ************************************************************************/

#include <cstdio>
#include <algorithm>

#define maxn 10000

int is_prime[maxn + 5], prime[maxn / 2], cnt;

// 初始化
void init(int n) {
    for (int i = 2; i <= n; i++) {
        if (!is_prime[i]) prime[cnt++] = i;
        for (int j = 0; j < cnt && i * prime[j] <= n; j++) {
            is_prime[i * prime[j]] = 1;
            if (!(i % prime[j])) break;
        }
    }
    return ;
}

// 处理
void handle(int s) {
    int l = s >> 1;
    int r = (s >> 1) + (s & 1);
    while (l && r) {
        if (!is_prime[l] && !is_prime[r]) {
            printf("%d\n", l * r);
            break;
        }
        l--;
        r++;
    }
    return ;
}

int main() {
    int s;
    scanf("%d", &s);
    init(s);
    handle(s);
    return 0;
}

