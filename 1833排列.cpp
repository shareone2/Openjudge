/*************************************************************************
*File Name: 排列.cpp
*Author: LiShiJie
*mail: 2659002865@qq.com
*Created Time: Wed Oct 21 10:44:20 2020
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <algorithm>
#define max_n 1024
using namespace std;

int m, n, k, num[max_n + 5];

// 初始化
void init() {
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &num[i]);
    }
    return ;
}

// 下一组排列
void nextpermutation() {
    int len = n;
    while (num[len - 1] > num[len]) len--; // 找到ai < ai + 1的情况
    // 二分查找后面的第一个小于num[len - 1]的值的位置再减一，并于其交换
    if (len != 1) swap(num[len - 1], *(upper_bound(num + len, num + n + 1, num[len - 1], greater<int>()) - 1));
    reverse(num + len, num + n + 1); // 反转len以及后面的数字
    return ;
}

// 处理
void handle() {
    for (int i = 1; i <= k; i++) {
        nextpermutation();
    }
    return ;
}

// 输出
void out_put() {
    for (int i = 1; i <= n; i++) {
        i != 1 && putchar(' ');
        printf("%d", num[i]);
    }
    putchar('\n');
    return ;
}

int main() {
    scanf("%d", &m);
    while (m--) {
        init();
        handle();
        out_put();
    }
    return 0;
}
