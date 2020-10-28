/*************************************************************************
*File Name: 2711合唱队形.cpp
*Author: LiShiJie
*mail: 2659002865@qq.com
*Created Time: Wed Oct 21 19:15:17 2020
 ************************************************************************/

#include <cstdio>
#include <algorithm>
#define max_n 100
using namespace std;

// n组数据，num存数，sum_lr存左右最长上升子序列之和, now_l存左最长上升子序列，now_r存右最长上升子序列
int n, num[max_n + 5], sum_lr[max_n + 5], now_l[max_n + 5], now_r[max_n + 5];
int left = 1, right = 1; // 左右管理指针

// 初始化(输入)
void init() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &num[i]);
    }
    return ;
}

// 左->右处理 || 右->左处理
void d_lr(int *now, int &dir, int loc) {
    if (num[loc] > now[dir - 1]) {
        now[dir++] = num[loc];
        sum_lr[loc] += dir - 2;
    } else {
        int *tmp = lower_bound(now + 1, now + dir, num[loc]);
        *tmp = num[loc];
        sum_lr[loc] += (tmp - now - 1);
    }
    return ;
}

// 处理
void handle() {
    for (int i = 1; i <= n; i++) { // 左右同时求最长上升子序列(严格递增)
        d_lr(now_l, left, i);
        d_lr(now_r, right, n - i + 1);
    }
    return ;
}

// 输出
void out_put() {
    int tmp = -1;
    for (int i = 1; i <= n; i++) {
        tmp = max(tmp, sum_lr[i]);
    }
    printf("%d\n", n - tmp - 1);
    return ;
}

int main() {
    init();
    handle();
    out_put();
    return 0;
}
