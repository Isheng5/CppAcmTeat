//
// Created by zengjiean on 2016/7/21 0021.
// Copyright (c) 2016 isheng5. All rights reserved.
// Coding是世界上最有趣的事情！
// 主要功能：hero
//
#include<iostream>
#include<algorithm>
#include <cstdio>

using namespace std;
struct Dota
{
    double DPS;
    double HP;
}hero[50];
bool cmp(Dota h1,Dota h2)
{
    return h1.DPS/h1.HP>h2.DPS/h2.HP;
}
int week2_k()
{
    int n,i,sum,total;
    while(~scanf("%d",&n))
    {
        total=0;
        for(i=0;i<n;i++)
        {
            scanf("%lf %lf",&hero[i].HP,&hero[i].DPS);//质疑先输入血量还是伤害值?
            total+=hero[i].DPS;
        }
        sort(hero,hero+n,cmp);
        sum=0;
        for(i=0;i<n;i++)
        {
            sum+=hero[i].HP*total;
            total-=hero[i].DPS;
        }
        printf("%d\n",sum);
    }
    return 0;
}
