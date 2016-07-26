//
// Created by zengjiean on 2016/7/25 0025.
// Copyright (c) 2016 isheng5. All rights reserved.
// Coding是世界上最有趣的事情！
// 主要功能：
//
#include<stdio.h>
#include<string.h>
int Map[100][100],intd[100],gn;
bool toolv[100];
int Prim()
{
    int i,j,mim,pt,ret;
    memset(intd,0x7f,sizeof(intd));
    memset(toolv,false,sizeof(toolv));
    pt=1;  toolv[1]=true;  ret=0;
    while( true){
        for( i=1; i<=gn; i++)
            if( !toolv[i]&&Map[pt][i]&&intd[i]>Map[pt][i])
                intd[i]=Map[pt][i];
        pt=-1; mim=0x7fffffff;
        for( i=1; i<=gn; i++){
            if( !toolv[i]&&mim>intd[i] ){
                mim=intd[i];
                pt=i;
            }
        }
        if( pt==-1) break;
        ret+=mim; toolv[pt]=true;
    }
    return ret;
}
int w3g()
{
    int m,i,j,c;
    while( scanf("%d",&gn)&&gn){
        m=gn*(gn-1)/2;
        memset(Map,0,sizeof(Map));
        while( m--){
            scanf("%d%d%d",&i,&j,&c);
            Map[i][j]=c;
            Map[j][i]=c;
        }
        printf("%d\n",Prim());
    }
    return 0;
}