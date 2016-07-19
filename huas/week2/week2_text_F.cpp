//
// Created by zengjiean on 2016/7/19 0019.
// Copyright (c) 2016 isheng5. All rights reserved.
// Coding是世界上最有趣的事情！
// 主要功能：F - A Simple Problem with Integers
//
#include <iostream>
#include <cstdio>
using namespace std;
const int W2tfMax = 100000 + 10;

struct W2tfTrees{
    W2tfTrees *left = NULL,*right = NULL;
    int l,r,sum = 0;
};

int nssx = 1;
W2tfTrees W2tfTree[W2tfMax * 3];

void W2tfStarTree(int l,int r,int &n,W2tfTrees *per,int tool){
    W2tfTree[n].l = l,W2tfTree[n].r = r,W2tfTree[n].sum = 0;
    if(n!=1 && tool == 1) per->left = &W2tfTree[n];
    if(n!=1 && tool == 2) per->right = &W2tfTree[n];
    if(l == r) {W2tfTree[n].right=W2tfTree[n].left = NULL; return;}
    int mid = (l + r) / 2;
    int nn = n;
    n ++;
    W2tfStarTree(l,mid,n,&W2tfTree[nn],1);
    n++;
    W2tfStarTree(mid+1,r,n,&W2tfTree[nn],2);
}

void W2tfPushTree(int l,int r,int n,W2tfTrees *root){
    root -> sum += n;
    cout<<root->sum<<"  ("<<root->l<<" "<<root->r<<")  "<<endl;
    int sum = root->sum;
    if(l == root -> l && r == root -> r) {return;}
    int mid = (root->l + root ->r) /2;
    if(l <= mid) W2tfPushTree(l,mid,n,root ->left);
    if(r > mid) W2tfPushTree(mid + 1,r,n,root->right);
    //else W2tfPushTree(mid + 1,r,n,root->right);
}

void W2tfOutTree(int l,int r,W2tfTrees *root,int &cou){
    if(root->l == l && root->r == r) {cou +=root->sum;return;}
    int mid = (root->l + root ->r) >> 1 ;
    if(l <= mid) W2tfOutTree(l,mid,root->left,cou);
    if(r > mid) W2tfOutTree(mid + 1,r,root->right,cou);
}

int week2_text_F(){
    int m,n,k,sum;
    freopen("in.txt", "r", stdin);
    cin >> m >> n;
    W2tfStarTree(1,m,nssx,NULL,1);
    W2tfTrees *sk = &W2tfTree[1];
//    while(sk != NULL){
//        cout<<sk->sum<<endl;
//        sk = sk->right;
//    }
    for (int i = 1; i <= m; ++i) {
        cin >> k;
        W2tfPushTree(i,i,k,&W2tfTree[1]);
    }
    while(sk != NULL){
        cout<<sk->sum<<"  ("<<sk->l<<" "<<sk->r<<")  "<<endl;
        sk = sk->right;
    }
    char s;
    int x;
    for (int j = 0; j < n; ++j) {
        cin >> s;
        if(s == 'Q') {cin >> m >> k;sum = 0;W2tfOutTree(m,k,&W2tfTree[1],sum);cout<<sum << endl;}
        else if(s == 'C') {cin >> m >> k>> x;W2tfPushTree(m,k,x,&W2tfTree[1]);}
        else continue;
    }
    getchar();
    getchar();
}