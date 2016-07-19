//
// Created by zengjiean on 2016/7/19 0019.
// Copyright (c) 2016 isheng5. All rights reserved.
// Coding是世界上最有趣的事情！
// 主要功能：
//

#include<iostream>
#include<cstdio>
using namespace std;

#define L l , m , u << 1
#define R m + 1 , r , u << 1 | 1

typedef long long w2tg_L;
const int N = 111111;
w2tg_L w2tg_add[N<<2];
w2tg_L w2tg_sum[N<<2];

void w2tf_PushUp(int u)//把当前结点的信息更新到父结点
{
    w2tg_sum[u] = w2tg_sum[u<<1] + w2tg_sum[u<<1|1];
}

void w2tg_PushDown(int u,int m)//把当前结点的信息更新给儿子结点
{
    if (w2tg_add[u]) {
        w2tg_add[u<<1] += w2tg_add[u];
        w2tg_add[u<<1|1] += w2tg_add[u];
        w2tg_sum[u<<1] += w2tg_add[u] * (m - (m >> 1));
        w2tg_sum[u<<1|1] += w2tg_add[u] * (m >> 1);
        w2tg_add[u] = 0;
    }
}

void build(int l,int r,int u)
{
    w2tg_add[u] = 0;
    if (l == r) {
        scanf("%lld",&w2tg_sum[u]);
        return ;
    }
    int m = (l + r) >> 1;
    build(L);
    build(R);
    w2tf_PushUp(u);
}

void update(int l1,int r1,int c,int l,int r,int u)
{
    if (l1 <= l && r <= r1) {
        w2tg_add[u] += c;
        w2tg_sum[u] += (w2tg_L)c * (r - l + 1);
        return ;
    }
    w2tg_PushDown(u , r - l + 1);
    int m = (l + r) >> 1;
    if (l1 <= m) update(l1 , r1 , c , L);
    if (m < r1) update(l1 , r1 , c , R);
    w2tf_PushUp(u);
}

w2tg_L query(int l1,int r1,int l,int r,int u)
{
    if (l1 <= l && r <= r1) {
        return w2tg_sum[u];
    }
    w2tg_PushDown(u , r - l + 1);
    int m = (l + r) >> 1;
    w2tg_L res = 0;
    if (l1<= m) res += query(l1 , r1 , L);
    if (m < r1) res += query(l1 , r1 , R);
    return res;
}

int week2_text_f()
{
    freopen("in.txt", "r", stdin);
    int N , Q;
    scanf("%d%d",&N,&Q);
    build(1 , N , 1);
    while (Q--) {
        char op[2];
        int a , b , c;
        scanf("%s",op);
        if (op[0] == 'Q') {
            scanf("%d%d",&a,&b);
            printf("%lld\n",query(a , b , 1 , N , 1));
        }
        else {
            scanf("%d%d%d",&a,&b,&c);
            update(a , b , c , 1 , N , 1);
        }
    }
    return 0;
}