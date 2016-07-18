//
// Created by zengjiean on 2016/7/18 0018.
// Copyright (c) 2016 isheng5. All rights reserved.
// Coding是世界上最有趣的事情！
// 主要功能：
//
#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

int w2tgGa[10001];

int week2_text_g(){
    int g;
    freopen("in.txt", "r", stdin);
    while(cin>>g){
        for (int i = 0; i < g; ++i)
            cin>>w2tgGa[i];
        sort(w2tgGa,w2tgGa + g);
        cout << w2tgGa[(g-1) / 2] << endl;
    }
}