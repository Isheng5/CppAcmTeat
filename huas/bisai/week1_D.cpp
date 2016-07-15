//
// Created by zengjiean on 2016/7/15 0015.
// Copyright (c) 2016 isheng5. All rights reserved.
// Coding是世界上最有趣的事情！
// 主要功能：
//
#include <stack>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int w1_D_MAX = 200;

stack<char> wl_s;
char w1_d_str[w1_D_MAX];

int d1_pro(){
    int x,y = -1;
    x = strlen(w1_d_str);
    while(!wl_s.empty()) wl_s.pop();
        for(int i = y + 1;i < x + 1;i++){
            if(w1_d_str[i] == '(' || w1_d_str[i] == '[') wl_s.push(w1_d_str[i]);
            if(w1_d_str[i] == ')' || w1_d_str[i] == ']'){
                if(wl_s.empty()) {printf("No\n");return 0;}
                else {
                    char ns = wl_s.top();
                    if (ns == '(' && w1_d_str[i] == ')') wl_s.pop();
                    else if (ns == '[' && w1_d_str[i] == ']') wl_s.pop();
                    else {
                        printf("No\n");
                        return 0;
                    }
                }
            }
        }
    if(!wl_s.empty()) {printf("No\n");return 0;}
    printf("Yes\n");
    return 0;
}

int week1_d(){
    int d_ns;
    char c;
    freopen("in.txt", "r", stdin);
    scanf("%d",&d_ns);
    getchar();
    for(int i = 0;i< d_ns;i++){
        w1_d_str[0] = '\0';
//        scanf("%s",w1_d_str);
//        cin>>w1_d_str;
//        while(gets(w1_d_str)){}
        gets(w1_d_str);
        if(w1_d_str[0] == '\0' || w1_d_str[0] == '\n') printf("Yes\n");
        else d1_pro();
    }
    return 0;
}