//
// Created by zengjiean on 2016/7/26 0026.
// Copyright (c) 2016 isheng5. All rights reserved.
// Coding是世界上最有趣的事情！
// 主要功能：
//
#include <iostream>
#include <cstdio>

using namespace std;
#define MAXV 30
#define inf 0x7ffffff

int map[MAXV][MAXV],n,d[MAXV],vis[MAXV];

void prim(){
    int i,j,mi,v;
    for(i=0;i<n;i++){
        d[i]=map[0][i];
        vis[i]=0;
    }
    for(i=1;i<=n;i++){
        mi=inf;
        for(j=0;j<n;j++){
            if(!vis[j] && mi>d[j]){
                v=j;
                mi=d[j];
            }
        }
        vis[v]=1;
        for(j=0;j<n;j++)
            if(!vis[j] && d[j]>map[v][j])        //和dijstra不同的一点是这里找的是最小邻边
                d[j]=map[v][j];
    }
    for(i=1;i<n;i++) d[0]+=d[i];
    printf("%d\n",d[0]);
}

int main(){
    int i,j,m,c;
    char a[2],b[2];
    while(scanf("%d",&n) && n){
        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
                if(i==j)
                    map[i][j]=0;
                else
                    map[i][j]=inf;
        for(i=1;i<n;i++){
            scanf("%s%d ",a,&m);
            for(j=0;j<m;j++){
                scanf("%s%d ",b,&c);
                map[a[0]-'A'][b[0]-'A']=map[b[0]-'A'][a[0]-'A']=c;
            }
        }
        prim();
    }
    return 0;
}