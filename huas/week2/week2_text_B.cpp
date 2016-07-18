//
// Created by zengjiean on 2016/7/18 0018.
// Copyright (c) 2016 isheng5. All rights reserved.
// Coding是世界上最有趣的事情！
// 主要功能：The Suspects 并查集的使用
//
#include <cstdio>
#define w2tb_max 30010

int w2tb_pre[w2tb_max];

void w2tbFind(int x,int& y){
    int r = x;
    if(w2tb_pre[r] == -1) {
        r = -1;
        y = -1;
        return;
    }
    while(w2tb_pre[r]!=r)
        r = w2tb_pre[r];
    int i = x,j;
    while(i!=r){
        j = w2tb_pre[i];
        w2tb_pre[i] = r;
        i = j;
    }
//    if(x == 0){
//        w2tb_pre[0] = 0;
//        w2tb_pre[r] = 0;
//        r = 0;
//    }
    y = r;
//    printf("%d ",y);
}

int week2_text_b(){
    int m,n,x,y,one;
    freopen("in.txt", "r", stdin);
    while(scanf("%d %d",&n,&m)!=EOF) {
        for (int k = 0; k <n; ++k) {
            w2tb_pre[k] = -1;
        }
        if(m == 0 && n == 0) break;
        while (m--){
            scanf("%d",&x);
            for (int i = 0; i < x; ++i) {
                scanf("%d",&y);
                if(i == 0) {
                    if(w2tb_pre[y] < 0)
                        w2tb_pre[y] = y,one = y;
                    else one = w2tb_pre[y];
                }
                else {
                    int xx;
                    w2tbFind(y,xx);
                    if(xx > -1){
                        w2tb_pre[one] = xx;
                        one = xx;
                    }
                    w2tb_pre[y] = one;
                }
                int xx;
                w2tbFind(w2tb_pre[y],xx);
            }
        }
//        w2tbFind(0);
        one = 0;
        y = 0;
        w2tbFind(y,m);
        int san;
        if(m == -1) printf("1\n");
        else {
            for (int j = 0; j < n; ++j) {
                w2tbFind(j,san);
                if (w2tb_pre[j] == m) one++;
//                printf("%d ", w2tb_pre[j]);
            }
//            printf("\n%d\n", m);
            printf("%d\n", one);
        }
    }
    return  0;
}
