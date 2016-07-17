//A - Is It A Tree?
// Created by zengjiean on 2016/7/17 0017.
// Copyright (c) 2016 isheng5. All rights reserved.
// Coding是世界上最有趣的事情！
// 主要功能：判断树
//
#include <cstdio>
#include <iostream>
using namespace std;
#define w2max 20

int Week2TextA[w2max],WeekText5[w2max];//建节点统计表。

void w2ta_star(){
    for (int i = 0; i < w2max; ++i) {
        Week2TextA[i] = 0;
        WeekText5[i] = 0;
    }
}

//int w2ta_process(){
//
//}

int week2_text_a(){
    int a,b,num,map,n = 0;
//    freopen("in.txt", "r", stdin);
    while(1){
        n ++;
        num = 0,map = 0;
        int ok = 0;
        w2ta_star();
        while(scanf("%d %d",&a,&b)){
            if(a == 0 || b == 0) break;
            if(a == -1 || b == -1) break;
            Week2TextA[b] ++;
            WeekText5[a] ++;
            num ++;
        }
        if(a == -1 || b == -1) break;
        for (int i = 1; i < w2max; ++i) {
            if(Week2TextA[i] > 1) {
                ok = 0;
                break;
            }
            else if(WeekText5[i] > 0 || Week2TextA[i] > 0) map ++;
            else continue;
        }
        if(num == map - 1 ){
            ok = 1;
        }
        if(num == 0) ok = 1;
        if(ok == 1) printf("Case %d is a tree.\n",n);
        else printf("Case %d is not a tree.\n",n);
        if(a == -1 || b == -1) break;
    }
    return 0;
}