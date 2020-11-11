/*************************************************************************
*File Name: 4142二分法求函数的零点.cpp
*Author: LiShiJie
*mail: 2659002865@qq.com
*Created Time: Wed Nov 11 09:36:18 2020
 ************************************************************************/

#include <iostream>
#include <cmath>
using namespace std;

double f(double x) {
    return pow(x, 5) - 15.0 * pow(x, 4) + 85.0 * pow(x, 3) - 225.0 * pow(x, 2) + 274.0 * x - 121.0;
}

int main() {
    double l = 1.5, r = 2.4;
    while (l <= r) {
        double mid = (l + r) / 2;
        if (r - l <= 0.0000001) {
            printf("%.6lf\n", mid);
            break;
        } else if (f(mid) > 0) {
            l = mid;
        } else {
            r = mid;
        }
    }
    return 0;
}
