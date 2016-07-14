//
// Created by zengjiean on 2016/7/14 0014.
// Copyright (c) 2016 isheng5. All rights reserved.
// Coding是世界上最有趣的事情！
// 主要功能：多向最优路径查找
//
#include <iostream>
#include <queue>
#include <cstdio>
using namespace std;

#define D_Max 202
#define D_Star_Max 10000000

struct D_MAP{
    char Map[D_Max][D_Max];
    int YStarX,YStarY;
    int MStarX,MStarY;
    int YSetup[D_Max][D_Max];
    int MSetup[D_Max][D_Max];
    bool YSetupTure[D_Max][D_Max];
    bool MSetupTure[D_Max][D_Max];
};

D_MAP d_sou;
queue<int> d_q;

void d_cin(int x,int y){
    for (int i = 0; i < x + 2; ++i) {
        for (int j = 0; j < y + 2; ++j) {
            if(i == 0 || j == 0 || i == x + 1 || j == y + 1) {
                d_sou.Map[i][j] = '#';
                d_sou.MSetup[i][j] = D_Star_Max;
                d_sou.YSetup[i][j] = D_Star_Max;
                d_sou.MSetupTure[i][j] = false;
                d_sou.MSetupTure[i][j] = false;
            }
            else {
                cin >> d_sou.Map[i][j];
                d_sou.MSetupTure[i][j] = d_sou.YSetupTure[i][j] = (('.' == d_sou.Map[i][j]) || ('@' == d_sou.Map[i][j]));
                d_sou.MSetup[i][j] = D_Star_Max,d_sou.YSetup[i][j] = D_Star_Max;
                if(d_sou.Map[i][j] == 'Y') d_sou.YStarX = i,d_sou.YStarY = j,d_sou.MSetupTure[i][j] = true;
                if(d_sou.Map[i][j] == 'M') d_sou.MStarX = i,d_sou.MStarY = j,d_sou.YSetupTure[i][j] = true;
            }
        }
    }
    d_sou.YSetup[d_sou.YStarX][d_sou.YStarY] = 0;
    d_sou.MSetup[d_sou.MStarX][d_sou.MStarY] = 0;
}

void d_bfs(){
    while (!d_q.empty()) d_q.pop();
    d_q.push(d_sou.YStarX),d_q.push(d_sou.YStarY);
    int x,y;
    while(!d_q.empty()){
        x = d_q.front(),d_q.pop();
        y = d_q.front(),d_q.pop();
        for (int i = -1; i < 2; ++i) {
            for (int j = -1; j < 2; ++j) {
                if(d_sou.YSetupTure[i + x][j + y] && (i == 0 || j == 0)){
                    d_sou.YSetupTure[i + x][j + y] = false;
                    if (d_sou.YSetup[x][y] + 1 <= d_sou.YSetup[i + x][j + y]) {
                        d_sou.YSetup[i + x][j + y] = d_sou.YSetup[x][y] + 1;
                    }
                    d_q.push(i + x),d_q.push(j + y);
                }
            }
        }
    }
    while (!d_q.empty()) d_q.pop();
    d_q.push(d_sou.MStarX),d_q.push(d_sou.MStarY);
    while(!d_q.empty()){
        x = d_q.front(),d_q.pop();
        y = d_q.front(),d_q.pop();
        for (int i = -1; i < 2; ++i) {
            for (int j = -1; j < 2; ++j) {
                if(d_sou.MSetupTure[i + x][j + y] && (i == 0 || j == 0)){
                    d_sou.MSetupTure[i + x][j + y] = false;
                    if (d_sou.MSetup[x][y] + 1 <= d_sou.MSetup[i + x][j + y]) {
                        d_sou.MSetup[i + x][j + y] = d_sou.MSetup[x][y] + 1;
                    }
                    d_q.push(i + x),d_q.push(j + y);
                }
            }
        }
    }

}

void d_cout(int x,int y){
    int min = D_Max;
    int adds;
    for (int i = 1; i < x + 1; ++i) {
        for (int j = 1; j < y + 1; ++j) {

///////////////////////////////////////////////////////////////////////////////
//            cout<<d_sou.MSetup[i][j]<< " ";
            ///////////////////////////////////////////////////////////////////////////////////

            if(d_sou.Map[i][j] == '@'){
                adds = d_sou.YSetup[i][j] + d_sou.MSetup[i][j];
                if(adds <= min) min = adds;
            }
        }
//        cout << endl;

    }
//    cout << endl;
    cout << min*11 <<endl;
}

int text_d(){
    int n,m;
    freopen("in.txt", "r", stdin);
    while(scanf("%d %d",&n,&m)!=EOF){
        d_cin(n,m);
        d_bfs();
        d_cout(n,m);
    }
    return 0;
}