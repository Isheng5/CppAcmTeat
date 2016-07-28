//
// Created by zengjiean on 2016/7/26 0026.
// Copyright (c) 2016 isheng5. All rights reserved.
// Coding是世界上最有趣的事情！
// 主要功能：
//
#include<cstdio>
#include <string>
#include <map>
using namespace std;
const int MAX_a = 60000;
char s[MAX_a*5],*NextStr;
int sum,n,m,kase,cnt,End[MAX_a];

struct Node {
    string s;
    int hash,left,right;
    bool operator < (const Node& u) const {
        if(hash != u.hash) return hash < u.hash;
        if(left != u.left) return left < u.left;
        return right < u.right;
    }
}Nodes[MAX_a];
map<Node,int> dict;
int parse() {
    int id = cnt++;
    Node& u = Nodes[id];
    u.left = u.right = -1 ;
    u.s = "";
    u.hash = 0;
    while(isalpha(*NextStr)) {
        u.hash = u.hash * 27 + *NextStr - 'a' + 1;
        u.s.push_back(*NextStr);
        ++NextStr;
    }
    if(*NextStr == '(') {
        NextStr++; u.left = parse(); NextStr++; u.right = parse(); NextStr++;
    }
    if(dict.count(u)) {
        id--; cnt--;
        return dict[u];
    }
    return dict[u] = id;
}
void print(int v) {
    if(End[v] == kase) printf("%d",v+1);
    else {
        End[v] = kase;
        printf("%s",Nodes[v].s.c_str());
        if(Nodes[v].left != -1) {
            printf("(");
            print(Nodes[v].left); //递归求得结点值并打印 。
            printf(",");
            print(Nodes[v].right);
            printf(")");
        }

    }
}
int main() {
    scanf("%d",&sum);
    for(kase = 1; kase <= sum; ++kase) {
        dict.clear();
        cnt = 0;
        scanf("%s",s);
        NextStr = s;
        print(parse());
        printf("\n");
    }
    return 0;
}

