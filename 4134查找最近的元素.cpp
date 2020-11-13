/*************************************************************************
*File Name: 4134查找最近的元素.cpp
*Author: LiShiJie
*mail: 2659002865@qq.com
*Created Time: Wed Nov 11 09:17:52 2020
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <cmath>
#define max_n 100000
using namespace std;

int n, num[max_n + 5], m;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> num[i];
    }
    cin >> m;
    for (int i = 0; i < m; i++) {
        int tmp;
        cin >> tmp;
        int *loc = lower_bound(num, num + n, tmp);
        if (loc - 1 - num >= 0 && fabs(*loc - tmp) >= tmp - *(loc - 1)) {
            cout << *(loc - 1) << endl; 
        } else {
            cout << *loc << endl;
        }
    }
    return 0;
}
