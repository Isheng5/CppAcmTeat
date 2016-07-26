//
// Created by zengjiean on 2016/7/22 0022.
// Copyright (c) 2016 isheng5. All rights reserved.
// Coding是世界上最有趣的事情！
// 主要功能：
//
#include <cstdio>
#include <algorithm>
using namespace std;

double Q[100];

int w2c(){
    int n,minnum,maxnum,sum;
    double min,max,mid,avg;
    while(scanf("%d",&n)!=EOF){
        if(n == 0) break;
        avg = 0;
        sum =0;
        min = 1000000;
        max = -1000000;
        for (int i = 1; i <= n; ++i) {
            scanf("%lf",&Q[i]);
            if(Q[i] > max) {max = Q[i];maxnum = i;}
            if(Q[i] < min) {min = Q[i];minnum = i;}
            avg +=Q[i];
        }
        double minsum = 1000000;
        avg = (avg - max - min) / (n-2);
        for (int j = 1; j <= n; ++j) {
            if(j == maxnum || j == minnum) continue;
            mid = abs(Q[j] - avg);
            if(mid < minsum) {minsum = mid;sum = j;}
        }
        printf("%d\n",sum);
    }
    return 0;
}