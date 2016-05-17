//
// Created by zengjiean on 16-5-17.
//
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
#define MAXN 100
int a[MAXN][MAXN];
int c33()
{
    int n, x, y, val=0;
    while(cin >> n && n!=EOF) {
        memset(a, 0, sizeof(a));// clear array
        int xuu = sizeof(n*n);
        val = a[x = 0][y = n - 1] = 1;// set the first element
        while (val < n * n) {
            while (x + 1 < n && !a[x + 1][y]) a[++x][y] = ++val;
            while (y - 1 >= 0 && !a[x][y - 1]) a[x][--y] = ++val;
            while (x - 1 >= 0 && !a[x - 1][y]) a[--x][y] = ++val;
            while (y + 1 < n && !a[x][y + 1]) a[x][++y] = ++val;
        }
        for (x = 0; x < n; ++x) {
            for (y = 0; y < n; ++y) {
                printf("%d", a[x][y]);
                if(y != n-1 ) printf(" ");
            }
            printf("\n");
        }
    }
    return 0;
}
