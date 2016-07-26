//
// Created by zengjiean on 2016/7/22 0022.
// Copyright (c) 2016 isheng5. All rights reserved.
// Coding是世界上最有趣的事情！
// 主要功能：
//
#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;
queue<int> w2bfs;

int w2s,w2n,w2m,w2setups,w2ok;
int w2sss,w2nnn,w2mmm;
bool w2tool[110][110][110];

void w2Bfs(){
    int setup,w2setup,w2ss,w2nn,w2mm ;
    if(w2sss == (w2s/2)) {w2ok = 1;return;}
    //{w2bfs.pop(),w2bfs.pop(),w2bfs.pop(),w2setups = w2bfs.front(),w2bfs.pop();w2ok = 1;return;}
    if(w2bfs.empty()) {w2ok = 0;return;}
    w2sss = w2bfs.front(),w2bfs.pop();
    w2nnn = w2bfs.front(),w2bfs.pop();
    w2mmm = w2bfs.front(),w2bfs.pop();
    w2setup = w2bfs.front();
    setup = w2bfs.front(),w2bfs.pop();
    w2ss = w2sss,w2nn = w2nnn,w2mm = w2mmm;
    if(!w2tool[w2ss][w2nn][w2mm]) return;
    w2tool[w2ss][w2nn][w2mm] = false;
    printf("------> w2ss %d w2nn %d w2mm %d w2setup %d w2setups %d\n", w2ss, w2nn, w2mm, w2setup, w2setups);
    if(w2ss > 0 && w2ss <= w2s && w2mm < w2m) {//s->m
        int mid = w2m - w2mm;
        if(w2ss >= mid) w2ss = w2ss - mid,w2mm = w2mm + mid;
        else w2mm = w2mm + w2ss,w2ss = 0;
        printf("s->m w2ss %d w2nn %d w2mm %d w2setup %d w2setups %d tool %d\n", w2ss, w2nn, w2mm, w2setup, w2setups,w2tool[w2ss][w2nn][w2mm] );
        if(w2tool[w2ss][w2nn][w2mm]) {
            w2bfs.push(w2ss), w2bfs.push(w2nn), w2bfs.push(w2mm);
//            w2tool[w2ss][w2nn][w2mm] = false;
            if(w2ss == w2nn){w2setups = w2setup;return;}
            w2setup = setup + 1;
            w2bfs.push(w2setup);
            w2Bfs();
        }
    }
    w2ss = w2sss,w2nn = w2nnn,w2mm = w2mmm;
    if(w2ss > 0 && w2ss <= w2s && w2nn < w2n) {//s->n
        int mid = w2n - w2nn;
        if(w2ss >= mid) w2ss = w2ss - mid,w2nn = w2nn + mid;
        else w2nn = w2nn + w2ss,w2ss = 0;
        printf("s->m w2ss %d w2nn %d w2mm %d w2setup %d w2setups %d tool %d\n", w2ss, w2nn, w2mm, w2setup, w2setups,w2tool[w2ss][w2nn][w2mm] );
        if(w2tool[w2ss][w2nn][w2mm]) {
            w2bfs.push(w2ss), w2bfs.push(w2nn), w2bfs.push(w2mm);
 //           w2tool[w2ss][w2nn][w2mm] = false;
            if(w2ss == w2nn){w2setups = w2setup;return;}
            w2setup = setup + 1;
            w2bfs.push(w2setup);

            w2Bfs();
        }
    }
    w2ss = w2sss,w2nn = w2nnn,w2mm = w2mmm;
    if(w2nn > 0 && w2nn <= w2n && w2mm < w2m) {//n->m
        int mid = w2m - w2mm;
        if(w2nn >= mid) w2nn = w2nn - mid,w2mm = w2mm + mid;
        else w2mm = w2mm + w2nn,w2nn = 0;
        printf("s->m w2ss %d w2nn %d w2mm %d w2setup %d w2setups %d tool %d\n", w2ss, w2nn, w2mm, w2setup, w2setups,w2tool[w2ss][w2nn][w2mm] );
        if(w2tool[w2ss][w2nn][w2mm]) {
            w2bfs.push(w2ss), w2bfs.push(w2nn), w2bfs.push(w2mm);
  //          w2tool[w2ss][w2nn][w2mm] = false;
            w2setup = setup + 1;
            if(w2ss == w2nn){w2setups = w2setup;return;}
            w2bfs.push(w2setup);

            w2Bfs();
        }
    }
    w2ss = w2sss,w2nn = w2nnn,w2mm = w2mmm;
    if(w2nn > 0 && w2nn <= w2n && w2ss < w2s) {//n->s
        int mid = w2s - w2ss;
        if(w2nn >= mid) w2nn = w2nn - mid,w2ss = w2ss + mid;
        else w2ss = w2ss + w2nn,w2nn = 0;
        printf("s->m w2ss %d w2nn %d w2mm %d w2setup %d w2setups %d tool %d\n", w2ss, w2nn, w2mm, w2setup, w2setups,w2tool[w2ss][w2nn][w2mm] );

        if(w2tool[w2ss][w2nn][w2mm]) {
            w2bfs.push(w2ss), w2bfs.push(w2nn), w2bfs.push(w2mm);
    //        w2tool[w2ss][w2nn][w2mm] = false;
            if(w2ss == w2nn){w2setups = w2setup;return;}
            w2setup = setup + 1;
            w2bfs.push(w2setup);

            w2Bfs();
        }
    }
    w2ss = w2sss,w2nn = w2nnn,w2mm = w2mmm;
    if((w2mm > 0) && (w2mm <= w2m) && (w2nn < w2n)) {//m->n
        int mid = w2n - w2nn;
        if(w2mm >= mid) w2mm = w2mm - mid,w2nn = w2nn + mid;
        else w2nn = w2nn + w2mm,w2mm = 0;
        printf("s->m w2ss %d w2nn %d w2mm %d w2setup %d w2setups %d tool %d\n", w2ss, w2nn, w2mm, w2setup, w2setups,w2tool[w2ss][w2nn][w2mm] );
        if(w2tool[w2ss][w2nn][w2mm]) {
            w2bfs.push(w2ss), w2bfs.push(w2nn), w2bfs.push(w2mm);
     //       w2tool[w2ss][w2nn][w2mm] = false;
            if(w2ss == w2nn){w2setups = w2setup;return;}
            w2setup = setup + 1;
            w2bfs.push(w2setup);

            w2Bfs();
        }
    }
    w2ss = w2sss,w2nn = w2nnn,w2mm = w2mmm;
    if(w2mm > 0 && w2mm <= w2m && w2ss < w2s) {//m->s
        int mid = w2s - w2ss;
        if(w2mm >= mid) w2mm = w2mm - mid,w2ss = w2ss + mid;
        else w2ss = w2ss + w2mm,w2mm = 0;
        printf("s->m w2ss %d w2nn %d w2mm %d w2setup %d w2setups %d tool %d\n", w2ss, w2nn, w2mm, w2setup, w2setups,w2tool[w2ss][w2nn][w2mm] );
        if(w2tool[w2ss][w2nn][w2mm]) {
            w2bfs.push(w2ss), w2bfs.push(w2nn), w2bfs.push(w2mm);
    //        w2tool[w2ss][w2nn][w2mm] = false;
            if(w2ss == w2nn){w2setups = w2setup;return;}
            w2setup = setup + 1;
            w2bfs.push(w2setup);

            w2Bfs();
        }
    }
    return;
}

int w2f(){
    while(scanf("%d %d %d",&w2s,&w2n,&w2m)!=EOF){
        if(w2s == 0) break;
        if(w2n == w2m) {printf("%d\n",2);continue;}
        if(w2s % 2 != 0) {printf("NO\n");continue;}
        if(w2n < w2m) swap(w2n,w2m);
        w2setups = 0, w2ok = 1;
        w2sss = w2s,w2nnn = w2mmm = 0;
        for (int i = 0; i < w2s + 1; ++i)
            for (int j = 0; j < w2n + 1; ++j)
                for (int k = 0; k < w2m + 1; ++k)
                    w2tool[i][j][k] = true;
        while (!w2bfs.empty()) w2bfs.pop();
        printf("------> %d %d %d\n",w2s,w2n,w2m);
        w2bfs.push(w2s),w2bfs.push(0),w2bfs.push(0),w2bfs.push(0);
  //      w2tool[w2s][0][0] = false;
        w2Bfs();
        if(w2ok) printf("%d\n",w2setups);
        else printf("NO\n");
    }
    return 0;
}