//
// Created by zengjiean on 2016/7/21 0021.
// Copyright (c) 2016 isheng5. All rights reserved.
// Coding是世界上最有趣的事情！
// 主要功能：
//
#include<iostream>
#include<cstdio>
using namespace std;
int MAX[4000001];
int SumMax(int a,int b)
{
    return a>b?a:b;
}
void PushUp(int rt)
{
    MAX[rt]=SumMax(MAX[rt<<1],MAX[(rt<<1)+1]);
}
void BuildTree(int l,int r,int rt)
{
    if(l==r)
    {
        scanf("%d",&MAX[rt]);
        return;
    }
    int m=(l+r)>>1;
    BuildTree(l,m,rt<<1);
    BuildTree(m+1,r,(rt<<1)+1);
    PushUp(rt);
}
void UpdateTree(int p,int q,int l,int r,int rt)
{
    if(l==r)
    {
        MAX[rt]=q;
        return;
    }
    int m=(l+r)>>1;
    if(p<=m)
        UpdateTree(p,q,l,m,rt<<1);
    else
        UpdateTree(p,q,m+1,r,(rt<<1)+1);
    PushUp(rt);
}
int GetSumMax(int L,int R,int l,int r,int rt)
{
    if(L<=l&&r<=R)
        return MAX[rt];
    int m=(r+l)>>1;
    int ret=0;
    if(L<=m)
        ret=SumMax(ret,GetSumMax(L,R,l,m,rt<<1));
    if(R>m)
        ret=SumMax(ret,GetSumMax(L,R,m+1,r,(rt<<1)+1));
    return ret;
}
int week2_e()
{
    int n,m,a,b,i;
    char c;
    while(~scanf("%d %d",&n,&m))
    {
        BuildTree(1,n,1);
        for(i=0;i<m;i++)
        {
            scanf("%*c%c%d %d",&c,&a,&b);
            if(c=='Q')
                printf("%d\n",GetSumMax(a,b,1,n,1));
            else
                UpdateTree(a,b,1,n,1);
        }
    }
    return 0;
}
