//
// Created by zengjiean on 2016/7/18 0018.
// Copyright (c) 2016 isheng5. All rights reserved.
// Coding是世界上最有趣的事情！
// 主要功能：
//
#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

vector<int> w2tcMap[50001];

int week2_text_c() {
    int N, K;
    freopen("in.txt", "r", stdin);
    scanf("%d%d", &N, &K);
    int w2tc_jia = 0;
    int zu[50001];
    for(int i = 1; i <= N; i++) zu[i] = i;
    int w2tcSta[50001] = {0};
    for(int i = 1; i <= N; i++) w2tcMap[i].push_back(i);
    for(int i = 0; i < K; i++){
        int zl, X, Y;
        scanf("%d %d %d", &zl, &X, &Y);
        if(X <= 0 || X > N || Y <= 0 || Y > N || (zl == 2 && X == Y)){
            w2tc_jia++;
            continue;
        }
        if(zu[X] == zu[Y]){
            if((zl == 1 && w2tcSta[X] != w2tcSta[Y]) || (zl == 2 && w2tcSta[Y] != (w2tcSta[X] + 1)%3)){
                w2tc_jia++;
            }
            continue;
        }
        int Xnum = w2tcMap[zu[X]].size(), Ynum = w2tcMap[zu[Y]].size();
        int zux = zu[X], zuy = zu[Y];
        int offset = 0;
        if(Xnum >= Ynum){
            //全部弄到X这边来
            if(zl == 1) offset = (w2tcSta[X] + 3 - w2tcSta[Y]) % 3;
            else offset = (w2tcSta[X] + 4 - w2tcSta[Y]) % 3;
            for(int j = 0; j < Ynum; j++){
                zu[w2tcMap[zuy][j]] = zux;
                w2tcSta[w2tcMap[zuy][j]] = (w2tcSta[w2tcMap[zuy][j]] + offset) % 3;
                w2tcMap[zux].push_back(w2tcMap[zuy][j]);
            }
        }
        else{
            if(zl == 1) offset = (w2tcSta[Y] + 3 - w2tcSta[X]) % 3;
            else offset = (w2tcSta[Y] + 2 - w2tcSta[X]) % 3;
            for(int j = 0; j < Xnum; j++){
                zu[w2tcMap[zux][j]] = zuy;
                w2tcSta[w2tcMap[zux][j]] = (w2tcSta[w2tcMap[zux][j]] + offset) % 3;
                w2tcMap[zuy].push_back(w2tcMap[zux][j]);
            }
        }
    }
    cout << w2tc_jia << endl;
    return 0;
}