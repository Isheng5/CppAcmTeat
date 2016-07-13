//
// Created by zengjiean on 2016/7/13 0013.
// Copyright (c) 2016 isheng5. All rights reserved.
// Coding是世界上最有趣的事情！
// 主要功能：求追牛的问题
//没注意内存泄漏，倒霉
//这个题目一直提交不过去，好tm倒霉，过会叫一个人帮我看看。。。。。。。
//我感觉我要挂了。
#include <iostream>
#include <cstdio>
#include <queue>
#define b_max 100010
//#include <stack>
using namespace std;

queue<int> t_b;
bool b_tak[b_max];

int b_queue(int k){
    int num = 0,frint,setup = 0,ss = 0;
    while(ss <= k){
        b_tak[ss] = true;
        ss++;
    }
    while(num != k){
        frint = t_b.front();
        t_b.pop();
//        s-- ;
        setup = t_b.front()+1;
        t_b.pop();
//        s--;
        for (int i = 0; i < 3; i++) {
            switch (i){
                case 0:
                    num = frint - 1;
                    break;
                case 1 :
                    num = frint + 1;
                    break;
                case 2:
                    num = frint * 2;
                    break;
            }
            if(num <= k && num >= 0 && b_tak[num]) {t_b.push(num);t_b.push(setup);b_tak[num] = false;}
            if(num == k) break;
        }
        if(num == k) break;
//        g.setup ++;
    }
//    cout << k << " "<< t_b.size() <<endl;
    while(!t_b.empty())
        t_b.pop();
    return setup;
}

int text_b(){
    int n,k;
//    freopen("in.txt", "r", stdin);
    while(scanf("%d %d",&n,&k)!=EOF){
        if(n >= k) {
            cout << n-k << endl;
            continue;}
        while(!t_b.empty())
            t_b.pop();
        t_b.push(n);
        b_tak[n] = false;
        t_b.push(0);
        cout << b_queue(k) <<endl;
    }
}