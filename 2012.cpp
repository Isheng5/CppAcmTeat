//
// Created by zengjiean on 16-4-17.
// 1523 2491
//求解指定范围的素数问题 打表的方法计算出范围中的所有素数

#include <iostream>
#include <cmath>
using namespace std;

int Pre[100];

int Pres(int x) {
    int max = 0,panduan = 1;
    max = sqrt(x);
    for (int i = 4;i <= max;i++){
        if(x % i == 0){
            panduan = 0;
            break;
        }
        i = i;
    }

    return panduan;
}

void StarPre(){
    int x = -39,Maxy = 50;
    for(x;x <= Maxy;x++){
        if(0 == (x * x + x + 41) % 2) Pre[x + 39] = 0;
        else if(0 == (x * x + x + 41) % 3) Pre[x + 39] = 0;
        else if(0 == (x * x + x + 41) % 5) Pre[x + 39] = 0;
        else if(0 == (x * x + x + 41) % 7) Pre[x + 39] = 0;
        else if(1 == Pres(x * x + x + 41)) Pre[x + 39] = 1;
        else Pre[x + 39] = 0;
      //  cout << "cshi:" << Pre[x +39] <<endl;
    }
}

int acm2012(){
    StarPre();
    int x,y;
    while (cin >> x >> y){
        if(x == 0 && y == 0) break;
        int sum = 0;
        for(int i = x;i <= y;i++) {
            if (Pre[i + 39] == 1) sum++;
            else break;
        }
        if(sum == (y - x +1)) cout << "OK"<<endl;
        else cout << "Sorry"<< endl;
    }
    return 0;
}