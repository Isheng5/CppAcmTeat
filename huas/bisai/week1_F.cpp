//
// Created by zengjiean on 2016/7/15 0015.
// Copyright (c) 2016 isheng5. All rights reserved.
// Coding是世界上最有趣的事情！
// 主要功能：
//
#include <iostream>
#include <cstdio>
#include <queue>
#include <cmath>
using namespace std;
const int w1_MAX = 12;

int w1_F_MAP[w1_MAX][w1_MAX][w1_MAX][w1_MAX],wl_setup,f_end;
queue<int> w1f;

bool d_prime(int n){
    int s = sqrt(n);
    for (int i = 2; i < s; ++i) {
        if(n%i == 0) return false;
    }
    return true;
}

int w1f_bfs(int x,int y,int m,int n,int sm){
    wl_setup = sm ;
    int setupsd = wl_setup;
    w1_F_MAP[x][y][m][n] = 1;
    if(x *1000 + y * 100 + m * 10 + n == f_end) return wl_setup;
    while(!w1f.empty()){
//        int a,b,c,d;
        x = w1f.front(),w1f.pop(),y = w1f.front(),w1f.pop(),m = w1f.front(),w1f.pop(),n = w1f.front(),w1f.pop();
        int sum;
 //       sum = x *1000 + y * 100 + m * 10 + n;
//        if(d_prime(sum)) {
            for (int i = -1; i < 2; ++i)
                for (int j = -1; j < 2; ++j)
                    for (int k = -1; k < 2; ++k)
                        for (int l = -1; l <2 ; ++l) {
                            if((j ==0 && k == 0 && l == 0)||(i == 0 && k == 0 && l == 0)||(i == 0 && j ==0 && l == 0)||(i == 0 && j == 0 && k == 0 ) && (x + i != 0)) {
                                if(x + i < 1 || y + j < 0 || m+k <0 || n + l < 0) continue;
                                sum = (x+i) *1000 + (y+j) * 100 + (m+k) * 10 + n;
                                if(1!=w1_F_MAP[x + i][y + j][m + k][n + l] && d_prime(sum)) {
                                    w1f.push(x+i),w1f.push(y+j),w1f.push(m+k),w1f.push(n+l);
                                    setupsd = wl_setup + 1;
                                    w1f_bfs(x+i,y+j,m+k,n+l,setupsd);
                                }
                            }
                        }
//        }
    }
}

int week1_f(){
    int n = 0,star;
    freopen("in.txt", "r", stdin);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >>star >>f_end;
        int x,y,m,nas;
        x = star / 1000;
        y = (star - x*1000)/100;
        m = (star - x*1000 - y*100)/10;
        nas = star % 10;
        wl_setup = 0;
        w1f.push(x),w1f.push(y),w1f.push(m),w1f.push(nas);
        cout<<w1f_bfs(x,y,m,nas,0)<<endl;
    }
    return 0;
}