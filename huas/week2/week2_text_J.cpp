//
// Created by zengjiean on 2016/7/21 0021.
// Copyright (c) 2016 isheng5. All rights reserved.
// Coding是世界上最有趣的事情！
// 主要功能：今年暑假不AC
//
#include <cstdio>
#include <algorithm>

using namespace std;
const int week2_j_max = 100+10;

struct week2_j_node{
    int time,star,end;
};

week2_j_node TimeList[week2_j_max];
bool TimeTools[40];

bool week2_j_cmp(week2_j_node x,week2_j_node y){
    return x.time < y.time || x.time == y.time && x.star < y.star;
}

int week2_j(){
    int n,x,y,sum;
    while(scanf("%d",&n)!=EOF){
        if(!n) break;
        for (int j = 0; j < 24; ++j) TimeTools[j] = true;
        sum = 0;
        for (int i = 0; i < n; ++i) {
            scanf("%d %d",&TimeList[i].star,&TimeList[i].end);
            TimeList[i].time = TimeList[i].star + TimeList[i].end;
        }
        sort(TimeList,TimeList+n,week2_j_cmp);
        int ok;
        for (int k = 0; k < n; ++k) {
            ok = 1;
            for (int i = TimeList[k].star; i <= TimeList[k].end; ++i) if(!TimeTools[i]) {ok = 0;break;}
            if(ok) {
                sum++;
                for (int i = TimeList[k].star; i < TimeList[k].end; ++i) TimeTools[i] = false;
            }
            else continue;
        }
        printf("%d\n",sum);

    }
    return 0;
}