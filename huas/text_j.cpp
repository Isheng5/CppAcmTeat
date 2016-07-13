//
// Created by zengjiean on 2016/7/13 0013.
// Copyright (c) 2016 isheng5. All rights reserved.
// Coding是世界上最有趣的事情！
// 主要功能：
//
#include <iostream>
#include <cstdio>
using namespace std;

const G_max = 7;

bool g_maze[G_max][G_max];

void g_cin(){
    int n;
    for (int i = 0; i < G_max; ++i) {
        for (int j = 0;j < G_max; ++j) {
            if (i == 0 || i == G_max-1 || j == 0 || j == G_max) g_maze[i][j] = false;
            cin >> n;
            g_maze[i][j] = n != 0;
        }
    }
}

void g_bfs(){

}

int text_g() {
    g_cin();
    g_bfs();
    g_cout();
    return 0;
}