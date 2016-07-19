//
// Created by zengjiean on 2016/7/19 0019.
// Copyright (c) 2016 isheng5. All rights reserved.
// Coding是世界上最有趣的事情！
// 主要功能：F - A Simple Problem with Integers
//
#include <iostream>
#include <cstdio>
using namespace std;
const W2tfMax = 100000 + 10;

struct W2tfTrees{
    W2tfTrees *left,*right;
    int l,r,sum;
};

int nssx = 1;
W2tfTrees W2tfTree[W2tfMax * 3];

void W2tfStarTree(int l,int r,int &n,W2tfTrees *next){
    W2tfTree[n].l = l,W2tfTree[n].r = r,W2tfTree[n].sum = 0;
    next = &W2tfTree[n];
    if(l == r) {W2tfTree[n].right=W2tfTree[n].left = NULL; return;}
    int mid = (l + r) >> 1;
    W2tfStarTree(l,mid,++n,W2tfTree[n].left);
    W2tfStarTree(mid+1,r,++n,W2tfTree[n].right);
}

void W2tfPushTree(int l,int r,int n,W2tfTrees *root){
    root -> sum += n;
    if(l == root -> l && r == root -> r) return;
    int mid = (root->l + root ->r) >> 1;
    if(l <= mid) W2tfPushTree(l,mid,n,root ->left);
    if(r > mid) W2tfPushTree(mid + 1,r,n,root->right);
}

void W2tfOutTree(int l,int r){

}

int week2_text_f(){
    int m,n,k;
    cin >> m >> n;
    W2tfStarTree(1,m,nssx,NULL);
    for (int i = 1; i <= m; ++i) {
        cin >> k;
        W2tfPushTree(i,i,k,&W2tfTree[1]);
    }
    char s;
    int x;
    for (int j = 0; j < n; ++j) {
        cin >> s;
        if(s == 'Q') {cin >> m >> k;W2tfOutTree(m,k);}
        else if(s == 'C') {cin >> m >> k>> x;W2tfPushTree(m,k,x,&W2tfTree[1]);}
    }
}