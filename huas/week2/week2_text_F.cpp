//
// Created by zengjiean on 2016/7/19 0019.
// Copyright (c) 2016 isheng5. All rights reserved.
// Coding是世界上最有趣的事情！
// 主要功能：F - A Simple Problem with Integers
//
#include <iostream>
#include <cstdio>
using namespace std;
const W2tfMax = 100000 + 10;

struct W2tfTrees{
    W2tfTrees *left,*right;
    int l,r,sum;
};

void W2tfStarTree(int n){

}

void W2tfPushTree(int l,int r,int n){

}

void W2tfOutTree(int l,int r){

}

int week2_text_f(){
    int m,n,k;
    cin >> m >> n;
    W2tfStarTree(m);
    for (int i = 1; i <= m; ++i) {
        cin >> k;
        W2tfPushTree(i,i,k);
    }
    char s;
    int x;
    for (int j = 0; j < n; ++j) {
        cin >> s;
        if(s == 'Q') {cin >> m >> k;W2tfOutTree(m,k);}
        else if(s == 'C') {cin >> m >> k>> x;W2tfPushTree(m ,k,x);}
    }
}