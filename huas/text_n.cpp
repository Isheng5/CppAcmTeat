//
// Created by zengjiean on 2016/7/14 0014.
// Copyright (c) 2016 isheng5. All rights reserved.
// Coding是世界上最有趣的事情！
// 主要功能：用链表的原理来重新构建数组
//
#include <iostream>
#include <cstdio>
#include <cstring>
const int n_max = 100000 +5;
int n_last,n_cur,n_next[n_max];
char n_s[n_max];

int text_n(){
    while(scanf("%s",n_s+1)==1){
        int n = strlen(n_s+1);
        n_last = n_cur = 0;
        n_next[0] = 0;

        for (int i = 1; i <= n; ++i) {
            char ch = n_s[i];
            if(ch == '[') n_cur = 0;
            else if(ch == ']') n_cur = n_last;
            else{
                n_next[i] = n_next[n_cur];
                n_next[n_cur] = i;
                if(n_cur == n_last) n_last = i;
                n_cur = i;
            }
        }
        for(int i = n_next[0];i != 0;i = n_next[i]) printf("%c",n_s[i]);
        printf("\n");
    }
    return 0;
}
