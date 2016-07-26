//
// Created by zengjiean on 2016/7/19 0019.
// Copyright (c) 2016 isheng5. All rights reserved.
// Coding是世界上最有趣的事情！
// 主要功能：
//
#include<cmath>
#include<cstdio>
#include <iostream>
#include<algorithm>
#include <iomanip>
using namespace std;

const double PI = acos(-1.0);

struct w2tl_Point{
    double x, y;
    w2tl_Point(double x = 0, double y = 0): x(x), y(y){}
    void scan(){
        cin>>x>>y;
    }
    bool operator < (const w2tl_Point &other){
        return y < other.y || (y == other.y && x < other.x);
    }
};

void rotate(w2tl_Point A, double rad,w2tl_Point& B){//向量旋转公式
    B.x = A.x * cos(rad) - A.y * sin(rad);
    B.y = A.y * cos(rad) + A.x * sin(rad);
}

int week2_text_l(){
    int n;
    w2tl_Point w2tl_p[3];
//    freopen("in.txt", "r", stdin);
    scanf("%d", &n);
    while(n--){
        w2tl_p[0].scan();
        rotate(w2tl_p[0], PI * 2 / 3,w2tl_p[1]);//逆时针旋转120度
        rotate(w2tl_p[0], -PI * 2 / 3,w2tl_p[2]);//顺时针旋转120度
        if (w2tl_p[2] < w2tl_p[1]) swap(w2tl_p[1], w2tl_p[2]);
        cout <<setiosflags(ios::fixed)<<setprecision(3)<<w2tl_p[1].x<<" "<<w2tl_p[1].y<<" ";
        cout <<setiosflags(ios::fixed)<<setprecision(3)<<w2tl_p[2].x<<" "<<w2tl_p[2].y<<endl;
    }
    return 0;
}