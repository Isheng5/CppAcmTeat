//
// Created by zengjiean on 2016/7/19 0019.
// Copyright (c) 2016 isheng5. All rights reserved.
// Coding是世界上最有趣的事情！
// 主要功能：敌兵布阵
//
#include <cstdio>

const int w2td_maxn = 55555;
int w2tdSum[w2td_maxn * 3];

void w2td_review(int rt)
{
    w2tdSum[rt] = w2tdSum[rt << 1] + w2tdSum[rt << 1 | 1];
}

void w2td_star(int l, int r, int rt)
{
    if (l == r)
    {
        scanf("%d", &w2tdSum[rt]);
        return;
    }
    int m = (l + r) >> 1;
    w2td_star(l, m, rt << 1);
    w2td_star(m + 1, r, rt << 1 | 1);
    w2td_review(rt);
}

void w2td_update(int p, int add, int l, int r, int rt)
{
    if (l == r)
    {
        w2tdSum[rt] += add;
        return;
    }
    int m = (l + r) >> 1;
    if (p <= m) w2td_update(p, add, l, m, rt << 1);
    else w2td_update(p, add, m + 1, r, rt << 1 | 1);
    w2td_review(rt);
}

int w2td_query(int ll, int rr, int l, int r, int rt)
{
    if (ll <= l && rr >= r) return w2tdSum[rt];
    int m = (l + r) >> 1;
    int ret = 0;
    if (ll <= m) ret += w2td_query(ll, rr, l, m, rt << 1);
    if (rr > m) ret += w2td_query(ll, rr, m + 1, r, rt << 1 | 1);
    return ret;
}

int week2_text_d()
{
    int t, c;
    char d[10];
    scanf("%d", &t);
    for (c = 1; c <= t; c++)
    {
        printf("Case %d:\n", c);
        int n;
        scanf("%d", &n);
        w2td_star(1, n, 1);
        while (scanf("%s", d) != EOF)
        {
            if (d[0] == 'E') break;
            int x, y;
            scanf("%d%d", &x, &y);
            if (d[0] == 'Q')
            {
                int ans = w2td_query(x, y, 1, n, 1);
                printf("%d\n", ans);
            }
            if (d[0] == 'S') w2td_update(x, -y, 1, n, 1);
            if (d[0] == 'A') w2td_update(x, y, 1, n, 1);
        }
    }
    return 0;
}