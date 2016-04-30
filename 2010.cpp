//
// Created by zengjiean on 16-4-17.
//
#include <iostream>
using namespace std;

int Shui[1000];

void coutshui(int m,int n,int& num){
    for(int i = m;i <= n;i++){
        int x,y,z;
        x = i / 100;
        y = (i - x*100)/10;
        z = i - x*100 - y*10;
        if(x*x*x + y*y*y + z*z*z == i){
            Shui[num] = i;
            num ++;
        }
    }
}

int acm2010(){
    int m,n;
    while(cin >> m >> n ){
        if(m > n || m < 100 || n > 999) break;
        int num=0;
        coutshui(m,n,num);
        if(num == 0) cout << "no" << endl;
        else {
            cout << Shui[0];
            for(int i=1;i < num;i++)
                cout <<" "<< Shui[i] ;
            cout << endl;
        }
    }
    return 0;
}

