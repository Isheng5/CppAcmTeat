//
// Created by zengjiean on 2016/7/14 0014.
// Copyright (c) 2016 isheng5. All rights reserved.
// Coding是世界上最有趣的事情！
// 主要功能：最短路径走出三维迷宫
//妈的智障，因为步数移动问题导致错误答案，好痛苦。。。。。。。。。
//感觉无爱了


#include <cstdio>
#include <iostream>
#include <queue>
using namespace std;
const int C_Max = 30 + 2;

struct c_map{
    char Map[C_Max][C_Max][C_Max];
    bool pic[C_Max][C_Max][C_Max];
    int setup;
};

c_map map_c;
queue<int> c_q;
int StarX,StarY,StarZ,EndX,EndY,EndZ;

void StarMap(int x,int y,int z){
    for (int i = 0; i < x + 2; ++i) {
        for (int j = 0; j < y + 2; ++j) {
            for (int k = 0; k < z + 2; ++k) {
                if (i == 0|| j==0 || k == 0 || i == x + 1 ||j == y + 1 || k == z + 1)
                {map_c.Map[i][j][k] = '#';map_c.pic[i][j][k] = false; }
                else{
                    cin >> map_c.Map[i][j][k];
                    map_c.pic[i][j][k] = map_c.Map[i][j][k] == '.';
                    if(map_c.Map[i][j][k] == 'S') {StarX = i,StarY = j,StarZ = k;}
                    if(map_c.Map[i][j][k] == 'E') {EndX = i,EndY = j,EndZ = k;map_c.pic[i][j][k] = true;}

                }
            }
        }
    }
    c_q.push(StarX),c_q.push(StarY),c_q.push(StarZ),c_q.push(0);
//    cout<<EndX << EndY << EndZ <<endl;
//    for (int i = 1; i < x + 1; ++i) {
//        for (int j = 1; j < y + 1; ++j) {
//            for (int k = 1; k < z + 1; ++k) {
//                    cout << map_c.pic[i][j][k] << " ";
//                }
//            cout << endl;
//            }
//        cout << endl;
//        }
//    for (int i = 1; i < x + 1; ++i) {
//        for (int j = 1; j < y + 1; ++j) {
//            for (int k = 1; k < z + 1; ++k) {
//                cout << map_c.Map[i][j][k] << " ";
//            }
//            cout << endl;
//        }
//        cout << endl;
//    }
}

void c_bfs(int x,int y,int z){
    map_c.setup = 0;
    int NextSetup = 0,i = StarX,j = StarY,k = StarZ;
    while(!c_q.empty()) c_q.pop();
    StarMap(x,y,z);
    while(!c_q.empty()){
        i = c_q.front();
        c_q.pop();
        j = c_q.front();
        c_q.pop();
        k = c_q.front();
        c_q.pop();
        map_c.setup = c_q.front();
        c_q.pop();
        NextSetup = map_c.setup;
        if(i == EndX && j == EndY && k == EndZ) {cout << "Escaped in " << map_c.setup  << " minute(s)." <<endl;return;}
        map_c.setup ++ ;
        for (int l = -1; l < 2; l++) {
            for (int m = -1; m < 2; m++) {
                for (int n = -1; n < 2; n++) {
                    if(map_c.pic[i + l][j + m][k + n] && ((l == 0 && m == 0) || (l == 0 && n == 0) || (m == 0 && n == 0))){
                        c_q.push(i + l),c_q.push(j + m),c_q.push(k + n),c_q.push(map_c.setup);
                        map_c.pic[i + l][j + m][k + n] = false;

//                        NextSetup = map_c.setup + 1;
                    }
                }
            }
        }
    }
    cout << "Trapped!" << endl;
    return;
}

int text_c(){
    int x,y,z;
//    freopen("in.txt", "r", stdin);
    while(scanf("%d %d %d",&x,&y,&z)!=EOF){
        if(x==0 && y == 0 && z ==0) break;
        c_bfs(x,y,z);
    }
    return 0;
}