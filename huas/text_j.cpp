//
// Created by zengjiean on 2016/7/13 0013.
// Copyright (c) 2016 isheng5. All rights reserved.
// Coding是世界上最有趣的事情！
// 主要功能：
//
//#include<cstdio>
//#include<iostream>
//
//#define N 5
//using namespace std;
//struct note {
//    int x, y, pre;//存放坐标，前一个节点在队列中的位置
//} que[100];
//
//int map[N][N];
//int Nx[4] = {1, -1, 0, 0};
//int Ny[4] = {0, 0, -1, 1};
//int start = 0, end = 1;
//
////用que结构体数组模拟一个队列
//void print(int s) {
//    if (que[s].pre != -1) {
//        //递归输出
//        print(que[s].pre);//根据查找前一个的位置来递归
//        cout << "(" << que[s].x << ", " << que[s].y << ")" << endl;
//    }
//}
//
//void bfsMap(int x, int y) {
//    que[start].pre = -1;
//    que[start].x = x;
//    que[start].y = y;
//    while (start < end) {
//        for (int i = 0; i < 4; i++) {
//            int a = Nx[i] + que[start].x;
//            int b = Ny[i] + que[start].y;
//            if (a < 0 || b < 0 || a >= N || b >= N || map[a][b])//如果出界或者遇到墙或者已经被访问
//                continue;
//            else {
//                map[a][b] = -1;//设置已经访问过
//                //入队
//                que[end].pre = start;
//                que[end].x = a;
//                que[end].y = b;
//                end++;//数组大小
//            }
//            if (a == N - 1 && b == N - 1)
//                print(start);
//        }
//        start++;
//    }
//}
//
//int text_j() {
////    freopen("in.txt", "r", stdin);
//    int i, j;
//    for (i = 0; i < N; i++)
//        for (j = 0; j < N; j++)
//            scanf("%d", &map[i][j]);
//    cout << "(0, 0)" << endl;
//    bfsMap(0, 0);
//    cout << "(" << N - 1 << ", " << N - 1 << ")" << endl;
//    return 0;
//}