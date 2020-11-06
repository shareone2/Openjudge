/*************************************************************************
*File Name: 2749分解因数.cpp
*Author: LiShiJie
*mail: 2659002865@qq.com
*Created Time: Thu Nov  5 16:18:09 2020
 ************************************************************************/

#include <stdio.h>
#include <math.h>
#define max_n 32768

int dfs(int x, int a) {
    int cnt = 0;
    for (int i = x; i <= sqrt(a); i++) {
        if (!(a % i)) cnt += dfs(i, a / i) + 1;
    }
    return cnt;
} 

int main() {
    int n;
    scanf("%d", &n);
    while (n--) {
        int a;
        scanf("%d", &a);
        printf("%d\n", dfs(2, a) + 1);
    }
    return 0;
}
