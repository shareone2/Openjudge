/*************************************************************************
*File Name: 4133垃圾炸弹.cpp
*Author: LiShiJie
*mail: 2659002865@qq.com
*Created Time: Wed Oct 28 09:09:19 2020
 ************************************************************************/

#include <cstdio>
#define maxed 1024

struct Node {
    int x, y, i;
};

struct Node node[25]; // 记录了每个d垃圾投放点的坐标
int d, n, loc[maxed + 5][maxed + 5], cnt, ans;

// 初始化
void init() {
    scanf("%d%d", &d, &n);
    for (int j = 1; j <= n; j++) {
        int x, y, i;
        scanf("%d%d%d", &x, &y, &i);
        node[j].i = i;
        node[j].x = x;
        node[j].y = y;
    }
    return ;
}

// 处理
void handle(int x, int y, int e) {
    for (int i = x - d; i <= x + d; i++) {
        if (i < 0 || i > maxed) continue;
        for (int j = y - d; j <= y + d; j++) {
            if (j < 0 || j > maxed) continue;
            loc[i][j] += node[e].i;
            if (loc[i][j] > ans) {
                ans = loc[i][j];
                cnt = 1;
            } else if (loc[i][j] == ans) {
                cnt++;
            }
        }
    }
    return ;
}

int main() {
    init();
    for (int j = 1; j <= n; j++) { // 对每个垃圾点处于投放炸弹的四个角进行枚举
        handle(node[j].x, node[j].y, j);
    }
    printf("%d %d\n", cnt, ans);
    return 0;
}
