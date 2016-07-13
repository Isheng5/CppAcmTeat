//
// Created by zengjiean on 2016/7/13 0013.
// Copyright (c) 2016 isheng5. All rights reserved.
// Coding是世界上最有趣的事情！
// 主要功能：
//
#include <iostream>
#include <cstdio>
#include <queue>
#include <stack>
using namespace std;

class text_bb{
public:
    int date;
    int setup;
    text_bb(int n,int m);

};

text_bb::text_bb(int n,int m) {
    date = n;
    setup = m;
}

queue<int> t_b;

void b_queue(int k,text_bb g){
    while(g.date != k){

    }
}

int text_b(){
    int n,k;
    while(cin>>n>>k){
        text_bb t_g(n,0);
        b_queue(k,t_g);
        cout << t_g.setup <<endl;
    }
}