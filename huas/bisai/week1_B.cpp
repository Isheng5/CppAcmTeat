//
// Created by zengjiean on 2016/7/15 0015.
// Copyright (c) 2016 isheng5. All rights reserved.
// Coding是世界上最有趣的事情！
// 主要功能：棋盘问题
//
#include <cstdio>
#include <iostream>
using namespace std;

const int W_B_MAX = 10;
char qipan[W_B_MAX][W_B_MAX];
int wb_jiance[W_B_MAX];
int b_n,b_k,tot;

void wb_cin(int n){
    for (int i = 0; i < n + 2; ++i) {
        for (int j = 0; j < n + 2; ++j) {
            if (0 == i || 0 == j || n + 1 == i || n + 1 == j){
                qipan[i][j] = '#';
            }
            else{
                cin >> qipan[i][j];
            }
        }
    }
}

void wb_pro(int b_cur,int csss){
//    cout<<b_cur <<" " << csss<<endl;
    if(b_cur == b_n + 1)
    {if(csss == b_k) tot ++;}///////////////////////
//    else if(b_cur == 0) {wb_jiance[b_cur] = 0;wb_pro(b_cur + 1);}
    else for(int i = 0;i < b_n + 1;i ++){
            int ok = 1,msm=0;
//            for(int j = 1;j < n + 1;j++){
                if(i == 0) { wb_jiance[i] = 0;wb_pro(b_cur + 1,msm);}
                if(qipan[b_cur][i] == '.') wb_jiance[b_cur] = i;
                for(int j = 1;j < b_cur;j++){
                    if(wb_jiance[b_cur] != 0 && wb_jiance[b_cur] == wb_jiance[j]){ok = 0;break; }
                    if(wb_jiance[j] > 0) msm++;
                }
                if(msm == b_k + 1) wb_jiance[b_cur] = 0;
                if(ok) wb_pro(b_cur + 1,msm);
 //           }
        }
}

int week1_b(){
    freopen("in.txt", "r", stdin);
    while (scanf("%d %d",&b_n,&b_k)!=EOF){
        if(b_n == -1 && b_k == -1) break;
        tot = 0;
        wb_cin(b_n);
        wb_pro(1,0);
        cout << tot<<endl;
    }
    return 0;
}